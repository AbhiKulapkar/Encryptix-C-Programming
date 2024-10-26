#include <opencv2/opencv.hpp>

#include <iostream>

using namespace cv;
using namespace std;

Mat image, processedImage;

void loadImage() {
    string path;
    cout << "Enter the image path: ";
    cin >> path;
    image = imread(path);
    if (image.empty()) {
        cout << "Could not open or find the image." << endl;
        return;
    }
    processedImage = image.clone();
    cout << "Image loaded successfully." << endl;
}

void displayImage(const Mat &img, const string &windowName) {
    namedWindow(windowName, WINDOW_AUTOSIZE);
    imshow(windowName, img);
    waitKey(0); // Wait for a keystroke in the window
}

void applyGrayscale() {
    cvtColor(processedImage, processedImage, COLOR_BGR2GRAY);
    cout << "Grayscale filter applied." << endl;
}

void applyBlur() {
    GaussianBlur(processedImage, processedImage, Size(15, 15), 0);
    cout << "Blur filter applied." << endl;
}

void applySharpen() {
    Mat kernel = (Mat_<float>(3, 3) << 0, -1, 0,
                                        -1, 5, -1,
                                         0, -1, 0);
    filter2D(processedImage, processedImage, processedImage.depth(), kernel);
    cout << "Sharpen filter applied." << endl;
}

void adjustBrightnessContrast() {
    double alpha;
    int beta;
    cout << "Enter alpha (contrast) [1.0 - 3.0]: ";
    cin >> alpha;
    cout << "Enter beta (brightness) [0 - 100]: ";
    cin >> beta;

    processedImage.convertTo(processedImage, -1, alpha, beta);
    cout << "Brightness and contrast adjusted." << endl;
}

void cropImage() {
    int x, y, width, height;
    cout << "Enter x, y, width, height for cropping: ";
    cin >> x >> y >> width >> height;
    
    if (x >= 0 && y >= 0 && width > 0 && height > 0 && 
        x + width <= processedImage.cols && y + height <= processedImage.rows) {
        processedImage = processedImage(Rect(x, y, width, height));
        cout << "Image cropped." << endl;
    } else {
        cout << "Invalid crop dimensions." << endl;
    }
}

void resizeImage() {
    int width, height;
    cout << "Enter new width and height: ";
    cin >> width >> height;
    resize(processedImage, processedImage, Size(width, height));
    cout << "Image resized." << endl;
}

void saveImage() {
    string outputPath;
    cout << "Enter the output file path (e.g., output.jpg): ";
    cin >> outputPath;
    if (imwrite(outputPath, processedImage)) {
        cout << "Image saved successfully." << endl;
    } else {
        cout << "Failed to save the image." << endl;
    }
}

void showMenu() {
    cout << "\nImage Processing Options:\n";
    cout << "1. Load Image\n";
    cout << "2. Display Image\n";
    cout << "3. Apply Grayscale Filter\n";
    cout << "4. Apply Blur Filter\n";
    cout << "5. Apply Sharpen Filter\n";
    cout << "6. Adjust Brightness and Contrast\n";
    cout << "7. Crop Image\n";
    cout << "8. Resize Image\n";
    cout << "9. Save Image\n";
    cout << "0. Exit\n";
    cout << "Choose an option: ";
}

int main() {
    int choice;
    do {
        showMenu();
        cin >> choice;
        switch (choice) {
            case 1: loadImage(); break;
            case 2: displayImage(processedImage, "Processed Image"); break;
            case 3: applyGrayscale(); break;
            case 4: applyBlur(); break;
            case 5: applySharpen(); break;
            case 6: adjustBrightnessContrast(); break;
            case 7: cropImage(); break;
            case 8: resizeImage(); break;
            case 9: saveImage(); break;
            case 0: cout << "Exiting application." << endl; break;
            default: cout << "Invalid option. Try again." << endl;
        }
    } while (choice != 0);

    return 0;
}
