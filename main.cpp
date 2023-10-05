#include"car.h"
#include<fstream>
#include<iostream>
#include <vector>
using namespace std;
int main() {


	std::vector<SmartCar> smartCars; // 用于存储所有小车的容器



	for (int i = 0;i < 10;i++) {
		// 录入小车信息
		SmartCar car;
		string id = "cqusn" + to_string(i + 1);
		car.setID(id);


		Chassis chassis;
		chassis.setID("Car " + std::to_string(i + 1));
		chassis.setModel("SCOUT MINI");
		chassis.setWheelbase("451mm");
		chassis.setTrack("490mm");
		chassis.setGroundClearance("115mm");
		chassis.setMinTurningRadius("0m");
		chassis.setDriveType("四轮四驱");
		chassis.setMaxRange("10KM");

		car.setChassis(chassis);



		AGXKit agxKit;
		agxKit.setModel("AGX Xavier");
		agxKit.setAI("NVIDIA");
		agxKit.setCudaCores("5120");
		agxKit.setTensorCores("576");
		agxKit.setMemory("16 GB");
		agxKit.setStorage("512 GB");
		car.setAGXKit(agxKit);

		StereoCamera stereoCamera;
		stereoCamera.setModel("ZED");
		stereoCamera.setCamera("Dual");
		stereoCamera.setRGBFrameResolution("1080p");
		stereoCamera.setRGBFrameRate("30 fps");
		stereoCamera.setFOV("120 degrees");
		stereoCamera.setDepthFrameRate("15 fps");
		car.setStereoCamera(stereoCamera);

		Lidar lidar;
		lidar.setModel("HDL-64E");
		lidar.setChannels("64");
		lidar.setTestRange("120 meters");
		lidar.setPowerConsumption("10 W");
		car.setLidar(lidar);

		Gyro gyro;
		gyro.setModel("MPU-6050");
		gyro.setManufacturer("InvenSense");
		car.setGyro(gyro);

		Display display;
		display.setSize("11.6");
		display.setModel("super");
		car.setDisplay(display);

		Battery battery;
		battery.setParameters("24V/15Ah");
		battery.setExternalPower("24V");
		battery.setChargingTime("2H");
		car.setBattery(battery);
		Student student;
		std::string a, b;
		std::cout << "请输入第"<<i+1<<"位同学的姓名和学号";
		std::cin >> a >> b;
		student.setName(a );
		student.setStudentID(b);
		car.setStudent(student);
		smartCars.push_back(car);

		std::ofstream outputFile(id);

		for (const SmartCar& car : smartCars) {
			car.save(id+ ".txt");
			outputFile << std::endl;
		}

		outputFile.close();

	}


	std::string filename;
	std::ofstream outputFile(filename);

	for (const SmartCar& car : smartCars) {
		car.save(filename);
		outputFile << std::endl;
	}

	outputFile.close();
	char choice;
	int currentIndex = 0;

	do {
		ifstream carFile("cqusn" + to_string(currentIndex + 1) + ".txt");
		if (!carFile) {
			std::cout << "无法打开文件！" << std::endl;
			return 1;
		}

		std::string line;
		while (getline(carFile, line)) {
			std::cout << line << std::endl;
		}

		carFile.close();

		cout << "按n键显示下一辆小车信息，按p显示上一辆小车信息，按q退出程序：";
		cin >> choice;

		if (tolower(choice) == 'n') {
			currentIndex++;
			if (currentIndex >= 10) {
				currentIndex = 9;
			}
		}
		else if (tolower(choice) == 'p') {
			currentIndex--;
			if (currentIndex < 0) {
				currentIndex = 0;
			}
		}

	} while (tolower(choice) != 'q');


	return 0;
}