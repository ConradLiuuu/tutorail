#include <ros/ros.h>
#include <tutorial/id.h>

using namespace ros;

class Student
{
private:
  NodeHandle nh;
  ServiceServer server;

public:
  Student()
  {
    server = nh.advertiseService("student", &Student::callback, this);
  }

  bool callback(tutorial::id::Request &req, tutorial::id::Response &res)
  {
    if (req.name == "wu"){
      res.id = 4354;
      res.class_ = "506f";
    }
    if (req.name == "liu"){
      res.id = 4320;
      res.class_ = "606a";
    }
    if (req.name == "ko"){
      res.id = 4353;
      res.class_ = "606c";
    }
    if (req.name == "tsao"){
      res.id = 4104;
      res.class_ = "202f";
    }
    ROS_INFO("Student's name : %s", req.name.c_str());
    ROS_INFO("Student's id : %d", res.id);
    ROS_INFO("Student's class : %s", res.class_.c_str());
    ROS_INFO("------------------");
    return true;
  }
};

int main(int argc, char **argv)
{
  init(argc, argv, "student");
  Student student;
  ROS_INFO("Student server is opened");
  spin();
}
