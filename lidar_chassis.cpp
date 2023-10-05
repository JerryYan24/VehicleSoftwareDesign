#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 前向声明观察者类
class RadarObserver;

// 主题接口
class RadarSubject {
public:
    virtual void subscribe(RadarObserver* observer) = 0;
    virtual void unsubscribe(RadarObserver* observer) = 0;
    virtual void notify(int obstacleStatus) = 0;
};

// 观察者接口
class RadarObserver {
public:
    virtual void update(int obstacleStatus) = 0;
};

// 雷达模块作为主题
class LaserRadar : public RadarSubject {
private:
    vector<RadarObserver*> observers;
    int obstacleStatus;

public:
    void subscribe(RadarObserver* observer) override {
        observers.push_back(observer);
    }

    void unsubscribe(RadarObserver* observer) override {
        for (auto it = observers.begin(); it != observers.end(); ++it) {
            if (*it == observer) {
                observers.erase(it);
                break;
            }
        }
    }

    void notify(int obstacleStatus) override {
        this->obstacleStatus = obstacleStatus;
        for (auto observer : observers) {
            observer->update(obstacleStatus);
        }
    }

    // 模拟雷达更新障碍物状态
    void updateObstacleStatus() {
        int status;
        cout << "请输入障碍物状态（1:前方, 2:左前方, 3:右前方）: ";
        cin >> status;
        notify(status);
    }
};

// 底盘模块作为观察者
class Chassis : public RadarObserver {
public:
    void update(int obstacleStatus) override {
        if (obstacleStatus == 1) {
            cout << "底盘执行后退操作" << endl;
        } else if (obstacleStatus == 2) {
            cout << "底盘执行左转操作" << endl;
        } else if (obstacleStatus == 3) {
            cout << "底盘执行右转操作" << endl;
        }
    }
};

int main() {
    LaserRadar radar;
    Chassis chassis;

    // 订阅雷达主题
    radar.subscribe(&chassis);

    while (true) {
        radar.updateObstacleStatus();
    }

    return 0;
}
