#include "car.h"
#include<fstream>
void Wheel::setModel(const std::string& model) {
    this->model = model;
}

void Wheel::setSize(const std::string& size) {
    this->size = size;
}

void Wheel::print() const {
    std::cout << "Wheel Model: " << model << std::endl;
    std::cout << "Wheel Size: " << size << std::endl;
}

void Wheel::save(std::ofstream& file) const {
    file << "Wheel Model: " << model << std::endl;
    file << "Wheel Size: " << size << std::endl;
}

void Chassis::setID(const std::string& id) {
    this->id = id;
}

void Chassis::setModel(const std::string& model) {
    this->model = model;
}

void Chassis::setWheelbase(const std::string& wheelbase) {
    this->wheelbase = wheelbase;
}

void Chassis::setTrack(const std::string& track) {
    this->track = track;
}

void Chassis::setGroundClearance(const std::string& clearance) {
    this->groundClearance = clearance;
}

void Chassis::setMinTurningRadius(const std::string& radius) {
    this->minTurningRadius = radius;
}

void Chassis::setDriveType(const std::string& driveType) {
    this->driveType = driveType;
}

void Chassis::setMaxRange(const std::string& maxRange) {
    this->maxRange = maxRange;
}

void Chassis::setTires(const Wheel& frontLeft, const Wheel& frontRight, const Wheel& rearLeft, const Wheel& rearRight) {
    tires[0] = frontLeft;
    tires[1] = frontRight;
    tires[2] = rearLeft;
    tires[3] = rearRight;
}

void Chassis::print() const {
    std::cout << "Chassis ID: " << id << std::endl;
    std::cout << "Chassis Model: " << model << std::endl;
    std::cout << "Wheelbase: " << wheelbase << std::endl;
    std::cout << "Track: " << track << std::endl;
    std::cout << "Ground Clearance: " << groundClearance << std::endl;
    std::cout << "Minimum Turning Radius: " << minTurningRadius << std::endl;
    std::cout << "Drive Type: " << driveType << std::endl;
    std::cout << "Max Range: " << maxRange << std::endl;
    std::cout << "Tires: " << std::endl;
    for (int i = 0; i < 4; i++) {
        std::cout << "Tire " << i + 1 << ":" << std::endl;
        tires[i].print();
    }
}

void Chassis::save(std::ofstream& file) const {
    file << "Chassis ID: " << id << std::endl;
    file << "Chassis Model: " << model << std::endl;
    file << "Wheelbase: " << wheelbase << std::endl;
    file << "Track: " << track << std::endl;
    file << "Ground Clearance: " << groundClearance << std::endl;
    file << "Minimum Turning Radius: " << minTurningRadius << std::endl;
    file << "Drive Type: " << driveType << std::endl;
    file << "Max Range: " << maxRange << std::endl;
    file << "Tires: " << std::endl;
    for (int i = 0; i < 4; i++) {
        file << "Tire " << i + 1 << ":" << std::endl;
        tires[i].save(file);
    }
}

void AGXKit::setModel(const std::string& model) {
    this->model = model;
}

void AGXKit::setAI(const std::string& ai) {
    this->ai = ai;
}

void AGXKit::setCudaCores(const std::string& cudaCores) {
    this->cudaCores = cudaCores;
}

void AGXKit::setTensorCores(const std::string& tensorCores) {
    this->tensorCores = tensorCores;
}

        void AGXKit::setMemory(const std::string & memory) {
        this->memory = memory;
    }

    void AGXKit::setStorage(const std::string & storage) {
        this->storage = storage;
    }

    void AGXKit::print() const {
        std::cout << "AGX Kit Model: " << model << std::endl;
        std::cout << "AI: " << ai << std::endl;
        std::cout << "CUDA Cores: " << cudaCores << std::endl;
        std::cout << "Tensor Cores: " << tensorCores << std::endl;
        std::cout << "Memory: " << memory << std::endl;
        std::cout << "Storage: " << storage << std::endl;
    }

    void AGXKit::save(std::ofstream & file) const {
        file << "AGX Kit Model: " << model << std::endl;
        file << "AI: " << ai << std::endl;
        file << "CUDA Cores: " << cudaCores << std::endl;
        file << "Tensor Cores: " << tensorCores << std::endl;
        file << "Memory: " << memory << std::endl;
        file << "Storage: " << storage << std::endl;
    }

    void StereoCamera::setModel(const std::string & model) {
        this->model = model;
    }

    void StereoCamera::setCamera(const std::string & camera) {
        this->camera = camera;
    }

    void StereoCamera::setRGBFrameResolution(const std::string & resolution) {
        this->rgbFrameResolution = resolution;
    }

    void StereoCamera::setRGBFrameRate(const std::string & frameRate) {
        this->rgbFrameRate = frameRate;
    }

    void StereoCamera::setFOV(const std::string & fov) {
        this->fov = fov;
    }

    void StereoCamera::setDepthFrameRate(const std::string & frameRate) {
        this->depthFrameRate = frameRate;
    }

    void StereoCamera::print() const {
        std::cout << "Stereo Camera Model: " << model << std::endl;
        std::cout << "Camera: " << camera << std::endl;
        std::cout << "RGB Frame Resolution: " << rgbFrameResolution << std::endl;
        std::cout << "RGB Frame Rate: " << rgbFrameRate << std::endl;
        std::cout << "FOV: " << fov << std::endl;
        std::cout << "Depth Frame Rate: " << depthFrameRate << std::endl;
    }

    void StereoCamera::save(std::ofstream & file) const {
        file << "Stereo Camera Model: " << model << std::endl;
        file << "Camera: " << camera << std::endl;
        file << "RGB Frame Resolution: " << rgbFrameResolution << std::endl;
        file << "RGB Frame Rate: " << rgbFrameRate << std::endl;
        file << "FOV: " << fov << std::endl;
        file << "Depth Frame Rate: " << depthFrameRate << std::endl;
    }

    void Lidar::setModel(const std::string & model) {
        this->model = model;
    }

    void Lidar::setChannels(const std::string & channels) {
        this->channels = channels;
    }

    void Lidar::setTestRange(const std::string & range) {
        this->testRange = range;
    }

    void Lidar::setPowerConsumption(const std::string & consumption) {
        this->powerConsumption = consumption;
    }

    void Lidar::print() const {
        std::cout << "Lidar Model: " << model << std::endl;
        std::cout << "Channels: " << channels << std::endl;
        std::cout << "Test Range: " << testRange << std::endl;
        std::cout << "Power Consumption: " << powerConsumption << std::endl;
    }

    void Lidar::save(std::ofstream & file) const {
        file << "Lidar Model: " << model << std::endl;
        file << "Channels: " << channels << std::endl;
        file << "Test Range: " << testRange << std::endl;
        file << "Power Consumption: " << powerConsumption << std::endl;
    }

    void Gyro::setModel(const std::string & model) {
        this->model = model;
    }

    void Gyro::setManufacturer(const std::string & manufacturer) {
        this->manufacturer = manufacturer;
    }

    void Gyro::print() const {
        std::cout << "Gyro Model: " << model << std::endl;
        std::cout << "Manufacturer: " << manufacturer << std::endl;
    }

    void Gyro::save(std::ofstream & file) const {
        file << "Gyro Model: " << model << std::endl;
        file << "Manufacturer: " << manufacturer << std::endl;
    }
    void Battery::setParameters(const std::string& parameters) {
        this->parameters = parameters;
    }

    void Battery::setExternalPower(const std::string& power) {
        this->externalPower = power;
    }

    void Battery::setChargingTime(const std::string& time) {
        this->chargingTime = time;
    }

    void Battery::print() const {
        std::cout << "Battery - Parameters: " << parameters << ", External Power: " << externalPower << ", Charging Time: " << chargingTime << std::endl;
    }

    void Battery::save(std::ofstream& file) const {
        file << "Battery - Parameters: " << parameters << ", External Power: " << externalPower << ", Charging Time: " << chargingTime << std::endl;
    }

    void Student::setStudentID(const std::string& id) {
        this->studentID = id;
    }

    void Student::setName(const std::string& name) {
        this->name = name;
    }

    void Student::print() const {
        std::cout << "Student - ID: " << studentID << ", Name: " << name << std::endl;
    }

    void Student::save(std::ofstream& file) const {
        file << "Student - ID: " << studentID << ", Name: " << name << std::endl;
    }

    void SmartCar::setID(const std::string& id) {
        this->id = id;
    }

    void SmartCar::setChassis(const Chassis& chassis) {
        this->chassis = chassis;
    }

    void SmartCar::setAGXKit(const AGXKit& agxKit) {
        this->agxKit = agxKit;
    }

    void SmartCar::setStereoCamera(const StereoCamera& stereoCamera) {
        this->stereoCamera = stereoCamera;
    }

    void SmartCar::setLidar(const Lidar& lidar) {
        this->lidar = lidar;
    }

    void SmartCar::setGyro(const Gyro& gyro) {
        this->gyro = gyro;
    }

    void SmartCar::setDisplay(const Display& display) {
        this->display = display;
    }

    void SmartCar::setBattery(const Battery& battery) {
        this->battery = battery;
    }

    void SmartCar::setStudent(const Student& student) {
        this->student = student;
    }

    void SmartCar::print() const {
        std::cout << "SmartCar - ID: " << id << std::endl;
        chassis.print();
        agxKit.print();
        stereoCamera.print();
        lidar.print();
        gyro.print();
        display.print();
        battery.print();
        student.print();
    }

    void SmartCar::save(const std::string& filename) const {
        std::ofstream file(filename);
        if (file.is_open()) {
            file << "SmartCar - ID: " << id << std::endl;
            chassis.save(file);
            agxKit.save(file);
            stereoCamera.save(file);
            lidar.save(file);
            gyro.save(file);
            display.save(file);
            battery.save(file);
            student.save(file);
            file.close();
        }
        else {
            std::cout << "Error opening file: " << filename << std::endl;
        }
    }void Display::setSize(const std::string& size) {
        this->size = size;
    }

    void Display::setModel(const std::string& model) {
        this->model = model;
    }

    void Display::print() const {
        std::cout << "Display - Size: " << size << ", Model: " << model << std::endl;
    }

    void Display::save(std::ofstream& file) const {
        file << "Display - Size: " << size << ", Model: " << model << std::endl;
    }