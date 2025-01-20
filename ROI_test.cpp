#include <opencv2/opencv.hpp>
using namespace cv;

int main() {
    // 가상의 프레임 초기화 (예제용)
    Mat frame = Mat::ones(400, 600, CV_8UC3) * 255; // 흰색 배경 (400x600)
    Mat edges = Mat::zeros(frame.size(), CV_8UC1);  // 에지 맵 (예제에서는 빈 이미지)
    Mat mask = Mat::zeros(edges.size(), edges.type());

    // 관심 영역(ROI) 설정
    Point points[1][4] = {
        {Point(frame.cols * 0.1, frame.rows * 0.9), Point(frame.cols * 0.45, frame.rows * 0.7), // 왼쪽 아래, 왼쪽 위
         Point(frame.cols * 0.55, frame.rows * 0.7), Point(frame.cols * 0.9, frame.rows * 0.9)}}; // 오른쪽 위, 오른쪽 아래
    const Point* ppt[1] = {points[0]};
    int npt[] = {4};

    // 다각형 영역을 마스크에 채우기
    fillPoly(mask, ppt, npt, 1, Scalar(255, 255, 255)); 

    // 원본 프레임에 다각형 그리기 (시각화용)
    Mat roiFrame = frame.clone(); // 프레임 복제
    polylines(roiFrame, ppt, npt, 1, true, Scalar(0, 0, 255), 2); // 다각형 외곽선을 빨간색으로 표시

    // 결과 보기
    imshow("Original Frame", frame);
    imshow("ROI Mask", mask);
    imshow("ROI Visualization", roiFrame);

    waitKey(0);
    return 0;
}