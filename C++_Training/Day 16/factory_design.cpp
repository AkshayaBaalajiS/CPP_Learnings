#include <iostream>
#include <memory>
using namespace std;

// Base Task Interface
class Task {
    public:
        virtual void performTask() = 0;
        virtual ~Task() = default;
};

// Task for drawing
class DrawTask : public Task {
    public:
        DrawTask() {
            cout << "@ DrawTask constructor\n";
        }
        void performTask() override {
            cout << "----Task is to Draw ----\n";
        }
        ~DrawTask() {
            cout << "@ DrawTask destructor\n";
        }
};

// Task for opening Adobe
class AdobeTask : public Task {
    public:
        AdobeTask() {
            cout << "@ AdobeTask constructor\n";
        }
        void performTask() override {
            cout << "----Task is to open Adobe ----\n";
        }
        ~AdobeTask() {
            cout << "@ AdobeTask destructor\n";
        }
};

// Task for opening Calculator
class CalcTask : public Task {
    public:
        CalcTask() {
            cout << "@ CalcTask constructor\n";
        }
        void performTask() override {
            cout << "----Task is to open Calculator ----\n";
        }
        ~CalcTask() {
            cout << "@ CalcTask destructor\n";
        }
};

// Task for opening Camera
class CameraTask : public Task {
    public:
        CameraTask() {
            cout << "@ CameraTask constructor\n";
        }
        void performTask() override {
            cout << "----Task is to open Camera ----\n";
        }
        ~CameraTask() {
            cout << "@ CameraTask destructor\n";
        }
};
// Factory Class
class TaskFactory {
    public:
        static Task* createTask(const string& taskType) {
            if (taskType == "DrawTask") {
                return new DrawTask();
            } else if (taskType == "AdobeTask") {
                return new AdobeTask();
            } else if (taskType == "CalcTask") {
                return new CalcTask();
            } else if (taskType == "CameraTask") {
                return new CameraTask();
            } else {
                return nullptr;
            }
        }
};

// Parent Task 1
class ParentTask1 {
    public:
        void callAllTasks() {
            Task* drawTask = TaskFactory::createTask("DrawTask");
            Task* adobeTask = TaskFactory::createTask("AdobeTask");
            if (drawTask) drawTask->performTask();
            if (adobeTask) adobeTask->performTask();
            delete drawTask;
            delete adobeTask;
        }
};

// Parent Task 2
class ParentTask2 {
    public:
        void callAllTasks() {
            Task* calcTask = TaskFactory::createTask("CalcTask");
            Task* cameraTask = TaskFactory::createTask("CameraTask");
            if (calcTask) 
            {
                calcTask->performTask();
            }
            if (cameraTask)
            {
                cameraTask->performTask();
            } 
            delete calcTask;
            delete cameraTask;
        }
};

int main() {
    cout << "Hi ..............\n";
    cout << "------------------\n";

    ParentTask1 parentTask1;
    parentTask1.callAllTasks();

    cout << "------------------\n";

    ParentTask2 parentTask2;
    parentTask2.callAllTasks();

    return 0;
}