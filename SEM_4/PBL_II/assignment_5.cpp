// Write a program to implement AVL tree for Dictionary. A Dictionary stores keywords & its meaning.
//  Provide facility for adding new keywords, updating meaning of any entry. 
// Provide a facility to display whole data sorted in ascending order. ->inorder traversal
// Also find how many maximum comparisons may require for finding any keyword.->search
//  Use a Height balanced tree and find the complexity for finding a keyword.->O(log n)-height of tree.
#include <iostream>
#include <cstring>
using namespace std;

class avl_node
{
    string word, meaning;
    avl_node *left, *right;

public:
    friend class avlTree;
};

class avlTree
{
    avl_node *root;

public:
    avlTree()
    {
        root = NULL;
    }

    int height(avl_node *);
    int diff(avl_node *);
    avl_node *LL_rotation(avl_node *);
    avl_node *RR_rotation(avl_node *);
    avl_node *LR_rotation(avl_node *);
    avl_node *RL_rotation(avl_node *);
    avl_node *balance(avl_node *);

    avl_node *insert(avl_node *, avl_node *);
    void insert();

    void inorder(avl_node *);
    void display_sorted();

    void update(string);
    int search(string);

    int getHeight() { return height(root); }
};

/* ---------- HEIGHT & BALANCE ---------- */

int avlTree::height(avl_node *temp)
{
    if (temp == NULL)
        return 0;
    return max(height(temp->left), height(temp->right)) + 1;
}

int avlTree::diff(avl_node *temp)
{
    return height(temp->left) - height(temp->right);
}

/* ---------- ROTATIONS ---------- */

avl_node *avlTree::LL_rotation(avl_node *parent)
{
    avl_node *temp = parent->left;
    parent->left = temp->right;
    temp->right = parent;
    return temp;
}

avl_node *avlTree::RR_rotation(avl_node *parent)
{
    avl_node *temp = parent->right;
    parent->right = temp->left;
    temp->left = parent;
    return temp;
}

avl_node *avlTree::LR_rotation(avl_node *parent)
{
    parent->left = RR_rotation(parent->left);
    return LL_rotation(parent);
}

avl_node *avlTree::RL_rotation(avl_node *parent)
{
    parent->right = LL_rotation(parent->right);
    return RR_rotation(parent);
}

avl_node *avlTree::balance(avl_node *temp)
{
    int bal = diff(temp);

    if (bal > 1)
    {
        if (diff(temp->left) > 0)
            temp = LL_rotation(temp);
        else
            temp = LR_rotation(temp);
    }
    else if (bal < -1)
    {
        if (diff(temp->right) > 0)
            temp = RL_rotation(temp);
        else
            temp = RR_rotation(temp);
    }
    return temp;
}

/* ---------- INSERT ---------- */

avl_node *avlTree::insert(avl_node *root, avl_node *temp)
{
    if (root == NULL)
    {
        return temp;
    }

    if (temp->word < root->word)
    {
        root->left = insert(root->left, temp);
    }
    else
    {
        root->right = insert(root->right, temp);
    }

    return balance(root);
}

void avlTree::insert()
{
    char ch;
    do
    {
        avl_node *temp = new avl_node;

        cout << "Enter keyword: ";
        cin >> temp->word;
        cout << "Enter meaning: ";
        cin >> temp->meaning;

        temp->left = temp->right = NULL;

        root = insert(root, temp);

        cout << "Add more? (Y/N): ";
        cin >> ch;

    } while (ch == 'Y' || ch == 'y');
}

/* ---------- DISPLAY (SORTED) ---------- */

void avlTree::inorder(avl_node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->word << " : " << root->meaning << endl;
        inorder(root->right);
    }
}

void avlTree::display_sorted()
{
    cout << "\nDictionary in Ascending Order:\n";
    inorder(root);
}

/* ---------- UPDATE ---------- */

void avlTree::update(string key)
{
    avl_node *temp = root;

    while (temp != NULL)
    {
        if (key == temp->word)
        {
            cout << "Enter new meaning: ";
            cin >> temp->meaning;
            cout << "Updated successfully!\n";
            return;
        }
        else if (key < temp->word)
            temp = temp->left;
        else
            temp = temp->right;
    }

    cout << "Keyword not found!\n";
}

/* ---------- SEARCH WITH COMPARISONS ---------- */

int avlTree::search(string key)
{
    avl_node *temp = root;
    int comparisons = 0;

    while (temp != NULL)
    {
        comparisons++;

        if (key == temp->word)
        {
            cout << "Found! Meaning: " << temp->meaning << endl;
            return comparisons;
        }
        else if (key < temp->word)
            temp = temp->left;
        else
            temp = temp->right;
    }

    cout << "Keyword not found!\n";
    return comparisons;
}

/* ---------- MAIN ---------- */

int main()
{
    avlTree t;
    int choice;
    string key;

    do
    {
        cout << "\n1.Insert\n2.Display\n3.Update\n4.Search\n5.Height\n6.Exit\n";
        cin >> choice;

        switch (choice)
        {
        case 1:
            t.insert();
            break;

        case 2:
            t.display_sorted();
            break;

        case 3:
            cout << "Enter keyword to update: ";
            cin >> key;
            t.update(key);
            break;

        case 4:
            cout << "Enter keyword to search: ";
            cin >> key;
            cout << "Comparisons: " << t.search(key) << endl;
            break;

        case 5:
            cout << "Height of tree: " << t.getHeight() << endl;
            break;
        }

    } while (choice != 6);

    return 0;
}