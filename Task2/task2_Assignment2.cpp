#include <iostream>

using namespace std;

class Led {

    public:

        virtual void write() = 0;
        virtual void read() = 0;
        virtual void toggle() = 0;
};


class AVR_Class : public Led {

    public:

       void write()
       {
         cout << "I am AVR_Class write Led" << endl;
       }

       void read()
       {
         cout << "I am AVR_Class read Led" << endl;
       }

       void toggle()
       {
         cout << "I am AVR_Class toggle Led" << endl;
       }

};


class ARM_Class : public Led {

    public:

       void write()
       {
         cout << "I am ARM_Class write Led" << endl;
       }

       void read()
       {
         cout << "I am ARM_Class read Led" << endl;
       }

       void toggle()
       {
         cout << "I am ARM_Class toggle Led" << endl;
       }
};

class Micro_Factory_Class {

    private:
      Led *Led_obj;

    public:

      Micro_Factory_Class(string type)
     {
       if(type == "ARM"){
         Led_obj = new ARM_Class();
       }

       else if(type == "AVR"){
         Led_obj = new AVR_Class();
       }

       else{
         Led_obj = NULL;
       }
     }

    ~Micro_Factory_Class()   {
      if (Led_obj)
      {
          delete[] Led_obj;
          Led_obj = NULL;
      }
    }

     Led* get_Led(){
       return Led_obj;
     }

};


int main()
{
    cout << "Hello world!" << endl;

    Micro_Factory_Class *p_factory = new Micro_Factory_Class("AVR");

    Led * p_led = p_factory->get_Led();

    p_led->write();
    p_led->read();
    p_led->toggle();


    return 0;
}
