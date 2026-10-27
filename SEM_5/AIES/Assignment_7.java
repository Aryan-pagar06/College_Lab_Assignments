import org.opencv.core.*;
import org.opencv.imgcodecs.Imgcodecs;
import org.opencv.imgproc.Imgproc;
import org.opencv.objdetect.CascadeClassifier;
import org.opencv.highgui.HighGui;

public class Main {

    public static void main(String[] args) {

        System.loadLibrary(Core.NATIVE_LIBRARY_NAME);

        // Read image
        Mat img = Imgcodecs.imread("face.jpg");

        if (img.empty()) {
            System.out.println("Error: Image not found!");
            return;
        }

        // Convert to grayscale
        Mat gray = new Mat();
        Imgproc.cvtColor(img, gray, Imgproc.COLOR_BGR2GRAY);

        // Load Haar Cascade classifier
        CascadeClassifier face = new CascadeClassifier(
            "haarcascade_frontalface_default.xml"
        );

        // Detect faces
        MatOfRect faces = new MatOfRect();

        face.detectMultiScale(gray, faces, 1.1, 5);

        // Draw rectangles around faces
        for (Rect r : faces.toArray()) {
            Imgproc.rectangle(
                img,
                new Point(r.x, r.y),
                new Point(r.x + r.width, r.y + r.height),
                new Scalar(0, 255, 0),
                2
            );
        }

        System.out.println("Faces detected: " + faces.toArray().length);

        // Display image
        HighGui.imshow("Face Detection", img);
        HighGui.waitKey(0);
        HighGui.destroyAllWindows();
    }
}