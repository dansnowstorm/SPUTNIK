#include "MyForm.h"
//#include "stdafx.h"
#include "math.h"

using namespace Project1;

[STAThreadAttribute]
int main(array<System::String^>^ args)
{
	// ��������� ���������� �������� Windows XP �� �������� �����-���� ��������� ����������
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	// �������� �������� ���� � ��� ������
	Application::Run(gcnew MyForm());
	return 0;
}

//static Pen^ p = gcnew Pen(Color::Red, 2);
//static Pen^ p1 = gcnew Pen(Color::White, 2);
static Point pt, pt1;

static int ix = 20, iy = 20, i2 = 1;

System::Void Project1::MyForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	Graphics^ gr = MyForm::CreateGraphics();
	System::Drawing::Color co = System::Drawing::Color::White;
	Pen^ p = gcnew Pen(Color::Green, 15);
	// Pen^p1=gcnew Pen(Color::White,2);
		//System::Drawing::Color c=System::Drawing::Color::Blue;
		// p->Width=3.0;
		// p->Color=System::Drawing::Color::Red;	
		// Point pt,pt1;
		//pt1.X=pt.X;pt1.Y=pt.Y;
	// gr->DpiX.ToString(); 
	MyForm::button1->Text = "12" + " " + gr->DpiX.ToString();
	gr->Clear(co);
	gr->DrawEllipse(p, 245, 145, 15.0, 15.0);
	gr->DrawEllipse(p, pt.X, pt.Y, 2.0, 2.0);
	return System::Void();
}

System::Void Project1::MyForm::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
	i2 = 0;


		


	//while (i2 <= 500)
	//{
	//	i2 = i2 + 1;
	//	p->Width = 3.0;
	//	p->Color = System::Drawing::Color::Black;
	//	grep->DrawEllipse(p, 500 - i2, 50, 8.0, 8.0);
	//	//for(int t=1;t<=100000;t++){;}
	//	p->Width = 3.0;
	//	//timer1->OnTick;
	//	for (int t = 1; t <= 1000000; t++) { ; }
	//	p->Color = System::Drawing::Color::White;
	//	grep->DrawEllipse(p, 500 - i2, 50, 8.0, 8.0);
	//}
	return System::Void();
}

System::Void Project1::MyForm::button3_Click(System::Object^ sender, System::EventArgs^ e)
{
	
	return System::Void();
}

System::Void Project1::MyForm::timer1_Tick(System::Object^ sender, System::EventArgs^ e)
{
	Graphics^ grip = MyForm::CreateGraphics();
	Pen^ peen = gcnew Pen(Color::Red, 15);
	ix = ix + 3;
	iy = iy + 8;
	if (ix == 1) { pt1.X = 80; pt1.Y = 80; }
	peen->Width = 3.0;
	peen->Color = System::Drawing::Color::White;
	grip->DrawEllipse(peen, pt1.X, pt1.Y, 8.0, 8.0);
	peen->Width = 3.0;
	peen->Color = System::Drawing::Color::Red;
	pt.X = 200 + 100 * System::Math::Cos(3.14 * ix / 180);
	pt.Y = 120 + 100 * System::Math::Sin(3.14 * ix / 180);
	grip->DrawEllipse(peen, pt.X, pt.Y, 8.0, 8.0);
	pt1.X = pt.X; pt1.Y = pt.Y;
	peen->Color = System::Drawing::Color::Violet;

	pt.X = 200 + 100 * System::Math::Cos(3.14 * (ix - 10) / 180);
	pt.Y = 120 + 100 * System::Math::Sin(3.14 * (ix - 10) / 180);
	grip->DrawLine(peen, 4 + pt.X, 4 + pt.Y, 5 + pt.X, 5 + pt.Y);
	peen->Width = 38.0;
	pt.X = 200 + 100 * System::Math::Cos(3.14 * (ix - 80) / 180);
	pt.Y = 120 + 100 * System::Math::Sin(3.14 * (ix - 80) / 180);
	peen->Color = System::Drawing::Color::White;
	grip->DrawLine(peen, pt.X, pt.Y, 5 + pt.X, 5 + pt.Y);
	return System::Void();
}

System::Void Project1::MyForm::label1_Click(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}

System::Void Project1::MyForm::timer2_Tick(System::Object^ sender, System::EventArgs^ e)
{
	Graphics^ grep = MyForm::CreateGraphics();
	Pen^ p = gcnew Pen(Color::Red, 15);
	int r = 0;
	p->Width = 5.0;
	p->Color = System::Drawing::Color::White;
	grep->DrawEllipse(p, 500 - i2 - 5, 50, 10.0, 10.0);
	p->Width = 3.0;
	p->Color = System::Drawing::Color::Black;
	grep->DrawEllipse(p, 500 - i2, 50, 8.0, 8.0);


	r = System::Math::Sqrt(Math::Pow(500 - i2, 2) + (125 - 50) * (125 - 50));
	button3->Text = r.ToString();
	i2 = i2 + 5;
}
