#pragma once
#include<utility>
#include<iostream>
#include<string>


class Parameters
{
public:
    Parameters(){}
};

class DirectionParameters: public Parameters{
private:
    std::string dir;
public:
    DirectionParameters(std::string Dir):dir(Dir){}
    std::string get_Dir(){
        return dir;
    }
};

class Command
{
protected:
    std::shared_ptr<Parameters> params;
public:
    Command(){}
    virtual ~Command(){}
    void set_parameters(std::shared_ptr<Parameters> parameters){
        params = parameters;
    }
    virtual void exec() = 0;
};

class Notification
{
public:
    Notification(){}
    virtual ~Notification(){}
    virtual void exec() = 0;
};




