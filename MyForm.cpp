#include "MyForm.h"
#include "math.h"
/// итерация 0.1 секунды == 1 минута == 60 sec
// 1 px == 1000000 m == 1000 km
// Центр земли в точке 400 х 400
// Расстояние до земли SPDx - 400 SPDy - 400 корень из суммы квадратов
// действие гравитации в течении 60 секунд = изменение скорости по x и y
// Для удобства МОЖНО?!!! сократим все КОНСТАНТЫ на 1000000 !!! G, M, R. (10e-6) 1px == 10e6 m
// ------

class Sputnik {
public:
	double speedx; double speedy; double posx; double posy; double LtoE;
	const double Gravity = 6.674e-11; // 
	const double M = 5.9742e24;
	double gs = Gravity * M / pow((LtoE * 1000000), 2); // gs - ускорение м/с2
	int EarthX = 400; // + AND Global Var
	int EarthY = 400; // + AND Global Var
	//posy -= EarthX; 
	void GetNextPos(double speedx, double speedy, double posx, double posy) {
		this->speedx = speedx;
		this->speedy = speedy;
		this->posx = posx;
		this->posy = posy;
	}
	// Должны вернуть изменение + или - к скорости Х
	double newspeedx() {
		if (LtoE <= 6 && LtoE >= -6) { return 10; }
		else { return -gs * (posx - EarthX) / LtoE; }
	}
	double newspeedy() {
		if (LtoE <= 6 && LtoE >= -6) { return 10; }
		else { return -gs * (posy - EarthY) / LtoE; }
		}
	double newposx() { return 1; }
	double newposy() { return 1; }
	double LtoEarth() { return sqrt(pow((posx-EarthX),2) + pow((posy-EarthY),2)); }
};


using namespace Project1;

[STAThread]
int main()
{
	Application::Run(gcnew Project1::MyForm);
	return 0;
}

// Таймер №1 Выводим переменные в лейблы
System::Void Project1::MyForm::timer1_Tick(System::Object^ sender, System::EventArgs^ e)
{
	MyForm::label1->Text = "X=" + DOT_X.ToString() + " Y=" + DOT_Y.ToString();
	//K_sin = System::Math::Sin(K_plusplus);
	//K_cos = System::Math::Cos(K_plusplus);
	MyForm::label2->Text = "Xsin=" + K_sin.ToString() + " Y=cos" + K_cos.ToString();
	//K_plusplus += 1;
	MyForm::label4->Text = "K_plusplus=" + K_plusplus.ToString();
	//DOT_XK = 200 + (100 * K_sin);
	//DOT_YK = 200 + (100 * K_cos);
	MyForm::label3->Text = "XKsin=" + DOT_XK.ToString() + " YK=cos" + DOT_YK.ToString();
	MyForm::label5->Text = "SPD1 " + "spX=" + SpeedX.ToString() + "spY=" + SpeedY.ToString() + "posX=" + PosX.ToString() + "posY=" + PosY.ToString();
	MyForm::label6->Text = "LtoEarthnow=" + LtoEarthnow.ToString();
	return System::Void();
}

System::Void Project1::MyForm::timer2_Tick(System::Object^ sender, System::EventArgs^ e)
{
	Graphics^ GDOT = MyForm::CreateGraphics();
	GDOT->Clear(Color::White);
	// Create a new pen Sputnik // Set the pen's width.
	Pen^ skyBluePen = gcnew Pen(Brushes::DeepSkyBlue);
	skyBluePen->Width = 8.0F;
	// Create a new pen Earth
	Pen^ EarthPen = gcnew Pen(Brushes::DarkBlue);
	EarthPen->Width = 6.0F;
	// Draw the Sputnik
	GDOT->DrawEllipse(skyBluePen, PosX, PosY, 2, 2);
	// Draw the Earth
	GDOT->DrawEllipse(EarthPen, (EarthX-6), (EarthY-6), 12, 12);
	//Dispose of the pen.
	delete skyBluePen;
	delete EarthPen;

	Sputnik SPD1 {SpeedX, SpeedY, PosX, PosY, LtoEarthnow};
	SpeedX += SPD1.newspeedx();
	SpeedY += SPD1.newspeedy();
	PosX += SpeedX;
	PosY += SpeedY;
	LtoEarthnow = SPD1.LtoEarth();
	double TEST = SPD1.newspeedx();
	MyForm::label7->Text = "Sputnik test=" + TEST.ToString();
	return System::Void();
}
