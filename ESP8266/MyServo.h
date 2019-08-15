#ifndef MYSERVO_H
#define MYSERVO_H

#include "Arduino.h"
#include <Servo.h>

class MyServo : public Servo{

    private:

    Servo x;

	public:

		MyServo(int porta);

		void fechar();
		void abrir();
		bool status();

        String _JANELA;
        String _SENSOR;

        String JSON_SENSOR(double temp_s);
        String JSON_JANELA();

        void uploadSENSOR(double temp_s);
        void uploadJANELA();


};

#endif;
