#include <iostream>

using namespace std;

pair<int, int> ResizeImage(pair<int, int> image, pair<int, int> restriction) {
    int length = max(image.first, image.second);
    int width = min(image.first, image.second);
    double ratio = length * 1.0 / width;
    int newLength = max(restriction.first, restriction.second);
    int newWidth = min(restriction.first, restriction.second);
    double newRatio = newLength * 1.0 / newWidth;
    if (newRatio > ratio) {
        return make_pair(newWidth * ratio, newWidth);
    } else {
        return make_pair(newLength, newLength / ratio);
    }
};

int main() {
    auto result = ResizeImage({800, 600}, {400, 400});
    cout << result.first << " " << result.second;
    return 0;
}