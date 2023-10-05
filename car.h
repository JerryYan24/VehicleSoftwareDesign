#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <fstream>
#include <string>

class Wheel {
private:
    std::string model;
    std::string size;

public:
    void setModel(const std::string& model);
    void setSize(const std::string& size);
    void print() const;
    void save(std::ofstream& file) const;
};

class Chassis {
private:
    std::string id;
    std::string model;
    std::string wheelbase;
    std::string track;
    std::string groundClearance;
    std::string minTurningRadius;
    std::string driveType;
    std::string maxRange;
    Wheel tires[4];

public:
    void setID(const std::string& id);
    void setModel(const std::string& model);
    void setWheelbase(const std::string& wheelbase);
    void setTrack(const std::string& track);
    void setGroundClearance(const std::string& clearance);
    void setMinTurningRadius(const std::string& radius);
    void setDriveType(const std::string& driveType);
    void setMaxRange(const std::string& maxRange);
    void setTires(const Wheel& frontLeft, const Wheel& frontRight, const Wheel& rearLeft, const Wheel& rearRight);
    void print() const;
    void save(std::ofstream& file) const;
};

class AGXKit {
private:
    std::string model;
    std::string ai;
    std::string cudaCores;
    std::string tensorCores;
    std::string memory;
    std::string storage;

public:
    void setModel(const std::string& model);
    void setAI(const std::string& ai);
    void setCudaCores(const std::string& cudaCores);
    void setTensorCores(const std::string& tensorCores);
    void setMemory(const std::string& memory);
    void setStorage(const std::string& storage);
    void print() const;
    void save(std::ofstream& file) const;
};

class StereoCamera {
private:
    std::string model;
    std::string camera;
    std::string rgbFrameResolution;
    std::string rgbFrameRate;
    std::string fov;
    std::string depthFrameRate;

public:
    void setModel(const std::string& model);
    void setCamera(const std::string& camera);
    void setRGBFrameResolution(const std::string& resolution);
    void setRGBFrameRate(const std::string& frameRate);
    void setFOV(const std::string& fov);
    void setDepthFrameRate(const std::string& frameRate);
    void print() const;
    void save(std::ofstream& file) const;
};

class Lidar {
private:
    std::string model;
    std::string channels;
    std::string testRange;
    std::string powerConsumption;

public:
    void setModel(const std::string& model);
    void setChannels(const std::string& channels);
    void setTestRange(const std::string& range);
    void setPowerConsumption(const std::string& consumption);
    void print() const;
    void save(std::ofstream& file) const;
};

class Gyro {
private:
    std::string model;
    std::string manufacturer;

public:
    void setModel(const std::string& model);
    void setManufacturer(const std::string& manufacturer);
    void print() const;
    void save(std::ofstream& file) const;
};

class Display {
private:
    std::string size;
    std::string model;

public:
    void setSize(const std::string& size);
    void setModel(const std::string& model);
    void print() const;
    void save(std::ofstream& file) const;
};

class Battery {
private:
    std::string parameters;
    std::string externalPower;
    std::string chargingTime;

public:
    void setParameters(const std::string& parameters);
    void setExternalPower(const std::string& power);
    void setChargingTime(const std::string& time);
    void print() const;
    void save(std::ofstream& file) const;
};

class Student {
private:
    std::string studentID;
    std::string name;

public:
    void setStudentID(const std::string& id);
    void setName(const std::string& name);
    void print() const;
    void save(std::ofstream& file) const;
};

class SmartCar {
private:
    std::string id;
    Chassis chassis;
    AGXKit agxKit;
    StereoCamera stereoCamera;
    Lidar lidar;
    Gyro gyro;
    Display display;
    Battery battery;
    Student student;

public:
    void setID(const std::string& id);
    void setChassis(const Chassis& chassis);
    void setAGXKit(const AGXKit& agxKit);
    void setStereoCamera(const StereoCamera& stereoCamera);
    void setLidar(const Lidar& lidar);
    void setGyro(const Gyro& gyro);
    void setDisplay(const Display& display);
    void setBattery(const Battery& battery);
    void setStudent(const Student& student);
    void print() const;
    void save(const std::string& filename) const;
};

#endif  // CAR_H