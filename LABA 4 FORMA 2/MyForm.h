#pragma once
#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include <thread>
#include <process.h>

namespace LABA4FORMA2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Drawing::Drawing2D; // нужно дл€ рисовани€
	using namespace std;
	using namespace System::Threading;



	int x1, y1, x2, y2, x12, x22, y12, y22, r1, r12;
	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:

		void drawKrug()
		{
			srand(time(0));
			for (size_t i = 0; true; i++)
			{
				Sleep(1000);
				x1 = Convert::ToInt32(10 + rand() % 110);
				y1 = Convert::ToInt32(10 + rand() % 70);
				x2 = Convert::ToInt32(10 + rand() % 70);
				y2 = Convert::ToInt32(10 + rand() % 70);
				r1 = Convert::ToInt32(1 + rand() % 3);
				Pen^ myPen1 = gcnew Pen(Color::Black, 3.0f);
				switch (r1)
				{
				case 1:
					myPen1->Color = Color::Green;
					break;
				case 2:
					myPen1->Color = Color::Blue;
					break;
				case 3:
					myPen1->Color = Color::Red;
					break;
				}
				Graphics^ im = this->CreateGraphics();
				im->DrawEllipse(myPen1, x1, x2, y1, y2);
				
			}
		}
		void drawRec()
		{
			srand(time(0));
			for (size_t i = 0; true; i++)
			{
				Sleep(500);
				x12 = Convert::ToInt32(210 + rand() % 310);
				y12 = Convert::ToInt32(10 + rand() % 70);
				x22 = Convert::ToInt32(10 + rand() % 70);
				y22 = Convert::ToInt32(10 + rand() % 70);
				r12 = Convert::ToInt32(1 + rand() % 3);
				Pen^ myPen2 = gcnew Pen(Color::Red, 3.0f);
				switch (r1)
				{
				case 1:
					myPen2->Color = Color::Green;
					break;
				case 2:
					myPen2->Color = Color::Blue;
					break;
				case 3:
					myPen2->Color = Color::Red;
					break;
				}
				Graphics^ im2 = this->CreateGraphics();
				im2->DrawRectangle(myPen2, x12, x22, y12, y22);
				
			}
		}
		Thread^ th1;
		Thread^ th2;
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			
			timer1->Interval = 500;
			th1 = gcnew Thread(gcnew ThreadStart(this, &MyForm::drawRec));
			th1->Start();
			th2 = gcnew Thread(gcnew ThreadStart(this, &MyForm::drawKrug));
			th2->Start();
			//drawRec();
			//drawKrug();
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				th1->Abort();
				th2->Abort();
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::Timer^ timer1;
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(295, 382);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(731, 545);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);

		}
#pragma endregion

		//void drawKrug()
		//{
		//	x1 = Convert::ToInt32(10 + rand() % 70);
		//	y1 = Convert::ToInt32(10 + rand() % 70);
		//	x2 = Convert::ToInt32(10 + rand() % 70);
		//	y2 = Convert::ToInt32(10 + rand() % 70);
		//	r1 = Convert::ToInt32(1 + rand() % 3);
		//	Pen^ myPen1 = gcnew Pen(Color::Black, 3.0f);
		//	switch (r1)
		//	{
		//	case 1:
		//		myPen1->Color = Color::Green;
		//		break;
		//	case 2:
		//		myPen1->Color = Color::Blue;
		//		break;
		//	case 3:
		//		myPen1->Color = Color::Red;
		//		break;
		//	}
		//	Graphics^ im = this->CreateGraphics();
		//	/*array<Single>^ temp0 = { 5.0F,2.0F,5.0F,2.0F };
		//	greenPen->DashPattern = temp0;
		//	bluePen->DashPattern = temp0;*/
		//	im->DrawEllipse(myPen1, x1, x2, y1, y2);
		//}
		//void drawRec()
		//{
		//	x12 = Convert::ToInt32(70 + rand() % 170);
		//	y12 = Convert::ToInt32(70 + rand() % 170);
		//	x22 = Convert::ToInt32(70 + rand() % 170);
		//	y22 = Convert::ToInt32(70 + rand() % 170);
		//	r12 = Convert::ToInt32(1 + rand() % 3);
		//	Pen^ myPen2 = gcnew Pen(Color::Black, 3.0f);
		//	switch (r1)
		//	{
		//	case 1:
		//		myPen2->Color = Color::Green;
		//		break;
		//	case 2:
		//		myPen2->Color = Color::Blue;
		//		break;
		//	case 3:
		//		myPen2->Color = Color::Red;
		//		break;
		//	}
		//	Graphics^ im2 = this->CreateGraphics();
		//	/*array<Single>^ temp0 = { 5.0F,2.0F,5.0F,2.0F };
		//	greenPen->DashPattern = temp0;
		//	bluePen->DashPattern = temp0;*/
		//	im2->DrawRectangle(myPen2, x12, x22, y12, y22);
		//}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		/*timer1->Start();*/
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		/*Thread^ th1;
		th1 = gcnew Thread(gcnew ThreadStart(this, &MyForm::drawRec));
		th1->Start();
		Thread^ th2;
		th2 = gcnew Thread(gcnew ThreadStart(this, &MyForm::drawKrug));
		th2->Start();*/
		/*drawRec();
		drawKrug();*/
	}
	};
}
