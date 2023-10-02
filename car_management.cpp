//
// Created by R Yan on 2023/10/2.
//
#include <iostream>
#include <fstream>
#include <string>

#ifdef _WIN32
#define CLEAR_SCREEN "cls" // Windows系统下的清屏命令
#else
#define CLEAR_SCREEN "clear" // Unix/Linux系统下的清屏命令
#endif

using namespace std;

// 结构体定义
struct Chassis {
    string number;
    string model;
    double wheelbase;
    double track;
    double groundClearance;
    double minTurningRadius;
    string driveType;
    double maxRange;
    struct Tire {
        string model;
        double size;
    } tires[4];
};

struct AGXKit {
    string model;
    double aiPerformance;
    int cudaCores;
    int tensorCores;
    double gpuMemory;
    double storage;
};

struct Camera {
    string model;
    string cameraModel;
    string resolution;
    int frameRate;
    string fov;
    int depthFrameRate;
};

struct LaserRadar {
    string model;
    int channels;
    double testRange;
    double powerConsumption;
};

struct Gyroscope {
    string model;
    string manufacturer;
};

struct BatteryModule {
    string parameters;
    double externalPower;
    double chargingTime;
};

struct Student {
    string studentNumber;
    string studentName;
};

struct SmartCar {
    string carNumber;
    Chassis chassis;
    AGXKit agxKit;
    Camera camera;
    LaserRadar laserRadar;
    Gyroscope gyroscope;
    BatteryModule batteryModule;
    Student studentInfo;
};

// 函数声明
void inputCarInfo(SmartCar& car);
void assignCarsToStudents(SmartCar cars[], Student students[], int count);
void saveToFile(SmartCar cars[], int count);
void displayCarInfo(SmartCar car);

int main() {
    const int carCount = 10;
    SmartCar cars[carCount];
    Student students[carCount];

    cout << "录入智能小车信息：" << endl;
    for (int i = 0; i < carCount; ++i) {
        inputCarInfo(cars[i]);
    }

    cout << "录入学生信息：" << endl;
    for (int i = 0; i < carCount; ++i) {
        cout << "学生 " << i + 1 << "：" << endl;
        cout << "学号：";
        cin >> students[i].studentNumber;
        cout << "姓名：";
        cin >> students[i].studentName;
    }

    assignCarsToStudents(cars, students, carCount);
    saveToFile(cars, carCount);

    // 读取和显示信息
    char option;
    int currentCarIndex = 0;
    system(CLEAR_SCREEN);
    displayCarInfo(cars[currentCarIndex]);
    while (true) {

        cout << "按n键显示下一辆小车信息，按p显示上一辆小车信息，按q退出：";
        cin >> option;

        if (option == 'n' && currentCarIndex < carCount - 1) {
            currentCarIndex++;
            system(CLEAR_SCREEN);
            displayCarInfo(cars[currentCarIndex]);
        } else if (option == 'p' && currentCarIndex > 0) {
            currentCarIndex--;
            system(CLEAR_SCREEN);
            displayCarInfo(cars[currentCarIndex]);
        } else if (option == 'q') {
            break;
        } else {
            cout << "无效输入，请重试。" << endl;
        }
    }

    return 0;
}

void inputCarInfo(SmartCar& car) {
    cout << "请输入智能小车信息：" << endl;
    cout << "编号：";
    cin >> car.carNumber;

    cout << "底盘信息：" << endl;
    cout << "编号：";
    cin >> car.chassis.number;
    cout << "型号：SCOUT MINI" << endl;
    cout << "轴距：451mm" << endl;
    cout << "轮距：490mm" << endl;
    cout << "最小离地间隙：115mm" << endl;
    cout << "最小转弯半径：0m" << endl;
    cout << "驱动形式：四轮四驱" << endl;
    cout << "最大行程：10KM" << endl;

    for (int i = 0; i < 4; ++i) {
        cout << "轮胎 " << i + 1 << "：" << endl;
        cout << "型号：";
        cin >> car.chassis.tires[i].model;
        cout << "尺寸：175mm" << endl;
    }

    cout << "AGX套件信息：" << endl;
    cout << "型号：AGX Xavier" << endl;
    cout << "AI：32 TOPS" << endl;
    cout << "CUDA核心：512" << endl;
    cout << "Tensor CORE：64" << endl;
    cout << "显存：32G" << endl;
    cout << "存储：32G" << endl;

    cout << "双目摄像头信息：" << endl;
    cout << "型号：RealSense D435i" << endl;
    cout << "摄像头：D430" << endl;
    cout << "RGB帧分辨率：1920*1080" << endl;
    cout << "RGB帧率：30" << endl;
    cout << "FOV：87*58" << endl;
    cout << "深度帧率：90" << endl;

    cout << "多线激光雷达信息：" << endl;
    cout << "型号：RS-Helios-16p" << endl;
    cout << "通道数：16" << endl;
    cout << "测试范围：100m" << endl;
    cout << "功耗：8W" << endl;

    cout << "9轴陀螺仪信息：" << endl;
    cout << "型号：CH110" << endl;
    cout << "厂家：NXP" << endl;

    cout << "液晶显示屏信息：" << endl;
    cout << "尺寸：11.6" << endl;
    cout << "型号：super" << endl;

    cout << "电池模块信息：" << endl;
    cout << "参数：24V/15Ah" << endl;
    cout << "对外供电：24V" << endl;
    cout << "充电时长：2H" << endl;
}

void assignCarsToStudents(SmartCar cars[], Student students[], int count) {
    for (int i = 0; i < count; ++i) {
        cars[i].studentInfo = students[i];
    }
}

void saveToFile(SmartCar cars[], int count) {
    ofstream outFile("smart_cars.txt");
    if (!outFile.is_open()) {
        cout << "无法打开文件。" << endl;
        return;
    }

    for (int i = 0; i < count; ++i) {
        outFile << "智能小车信息：" << endl;
        outFile << "编号：" << cars[i].carNumber << endl;
        outFile << "底盘信息：" << endl;
        outFile << "编号：" << cars[i].chassis.number << endl;
        outFile << "型号：SCOUT MINI" << endl;
        outFile << "轴距：451mm" << endl;
        outFile << "轮距：490mm" << endl;
        outFile << "最小离地间隙：115mm" << endl;
        outFile << "最小转弯半径：0m" << endl;
        outFile << "驱动形式：四轮四驱" << endl;
        outFile << "最大行程：10KM" << endl;
        outFile << "轮胎信息：" << endl;
        for (int j = 0; j < 4; ++j) {
            outFile << "轮胎 " << j + 1 << "：" << endl;
            outFile << "型号：" << cars[i].chassis.tires[j].model << endl;
            outFile << "尺寸：175mm" << endl;
        }

        outFile << "AGX套件信息：" << endl;
        outFile << "型号：AGX Xavier" << endl;
        outFile << "AI：32 TOPS" << endl;
        outFile << "CUDA核心：512" << endl;
        outFile << "Tensor CORE：64" << endl;
        outFile << "显存：32G" << endl;
        outFile << "存储：32G" << endl;

        outFile << "双目摄像头信息：" << endl;
        outFile << "型号：RealSense D435i" << endl;
        outFile << "摄像头：D430" << endl;
        outFile << "RGB帧分辨率：1920*1080" << endl;
        outFile << "RGB帧率：30" << endl;
        outFile << "FOV：87*58" << endl;
        outFile << "深度帧率：90" << endl;

        outFile << "多线激光雷达信息：" << endl;
        outFile << "型号：RS-Helios-16p" << endl;
        outFile << "通道数：16" << endl;
        outFile << "测试范围：100m" << endl;
        outFile << "功耗：8W" << endl;

        outFile << "9轴陀螺仪信息：" << endl;
        outFile << "型号：CH110" << endl;
        outFile << "厂家：NXP" << endl;

        outFile << "液晶显示屏信息：" << endl;
        outFile << "尺寸：11.6" << endl;
        outFile << "型号：super" << endl;

        outFile << "电池模块信息：" << endl;
        outFile << "参数：24V/15Ah" << endl;
        outFile << "对外供电：24V" << endl;
        outFile << "充电时长：2H" << endl;

        outFile << "学生信息：" << endl;
        outFile << "学号：" << cars[i].studentInfo.studentNumber << endl;
        outFile << "姓名：" << cars[i].studentInfo.studentName << endl;

        outFile << endl;
    }

    outFile.close();
}

void displayCarInfo(SmartCar car) {
    cout << "智能小车信息：" << endl;
    cout << "编号：" << car.carNumber << endl;
    cout << "底盘信息：" << endl;
    cout << "编号：" << car.chassis.number << endl;
    cout << "型号：SCOUT MINI" << endl;
    cout << "轴距：451mm" << endl;
    cout << "轮距：490mm" << endl;
    cout << "最小离地间隙：115mm" << endl;
    cout << "最小转弯半径：0m" << endl;
    cout << "驱动形式：四轮四驱" << endl;
    cout << "最大行程：10KM" << endl;
    cout << "轮胎信息：" << endl;
    for (int j = 0; j < 4; ++j) {
        cout << "轮胎 " << j + 1 << "：" << endl;
        cout << "型号：" << car.chassis.tires[j].model << endl;
        cout << "尺寸：175mm" << endl;
    }

    cout << "AGX套件信息：" << endl;
    cout << "型号：AGX Xavier" << endl;
    cout << "AI：32 TOPS" << endl;
    cout << "CUDA核心：512" << endl;
    cout << "Tensor CORE：64" << endl;
    cout << "显存：32G" << endl;
    cout << "存储：32G" << endl;

    cout << "双目摄像头信息：" << endl;
    cout << "型号：RealSense D435i" << endl;
    cout << "摄像头：D430" << endl;
    cout << "RGB帧分辨率：1920*1080" << endl;
    cout << "RGB帧率：30" << endl;
    cout << "FOV：87*58" << endl;
    cout << "深度帧率：90" << endl;

    cout << "多线激光雷达信息：" << endl;
    cout << "型号：RS-Helios-16p" << endl;
    cout << "通道数：16" << endl;
    cout << "测试范围：100m" << endl;
    cout << "功耗：8W" << endl;

    cout << "9轴陀螺仪信息：" << endl;
    cout << "型号：CH110" << endl;
    cout << "厂家：NXP" << endl;

    cout << "液晶显示屏信息：" << endl;
    cout << "尺寸：11.6" << endl;
    cout << "型号：super" << endl;

    cout << "电池模块信息：" << endl;
    cout << "参数：24V/15Ah" << endl;
    cout << "对外供电：24V" << endl;
    cout << "充电时长：2H" << endl;

    cout << "学生信息：" << endl;
    cout << "学号：" << car.studentInfo.studentNumber << endl;
    cout << "姓名：" << car.studentInfo.studentName << endl;

    cout << endl;
}
