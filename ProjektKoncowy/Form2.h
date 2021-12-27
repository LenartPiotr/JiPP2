#pragma once

#include "RunSettings.h"
#include "BallsManager.h"

namespace CppCLRWinformsProjekt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Podsumowanie informacji o Form2
	/// </summary>
	public ref class Form2 : public System::Windows::Forms::Form
	{
	private:
		BufferedGraphics^ myBuffer;
		BallsManager* ballsManager;
		static const int widthCorrect = 16;
		static const int heightCorrect = 39;
	public:
		Form2(RunSettings *runSettings)
		{
			InitializeComponent();

			Width = runSettings->getWidth() + widthCorrect;
			Height = runSettings->getHeight() + heightCorrect;

			BufferedGraphicsContext^ currentContext;
			currentContext = BufferedGraphicsManager::Current;
			myBuffer = currentContext->Allocate(CreateGraphics(), DisplayRectangle);

			ballsManager = new BallsManager(*runSettings);
		}
	protected:
		~Form2()
		{
			if (components)
			{
				delete components;
			}
			delete ballsManager;
		}
	private: System::Windows::Forms::Timer^ drawTimer;
	private: System::Windows::Forms::Timer^ tickTimer;
	private: System::ComponentModel::IContainer^ components;

	private:

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Metoda wymagana do obs³ugi projektanta — nie nale¿y modyfikowaæ
		/// jej zawartoœci w edytorze kodu.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->drawTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->tickTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// drawTimer
			// 
			this->drawTimer->Enabled = true;
			this->drawTimer->Interval = 10;
			this->drawTimer->Tick += gcnew System::EventHandler(this, &Form2::drawTimer_Tick);
			// 
			// tickTimer
			// 
			this->tickTimer->Enabled = true;
			this->tickTimer->Interval = 10;
			this->tickTimer->Tick += gcnew System::EventHandler(this, &Form2::tickTimer_Tick);
			// 
			// Form2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"Form2";
			this->ResumeLayout(false);

		}
#pragma endregion

	private:
		System::Void drawTimer_Tick(System::Object^ sender, System::EventArgs^ e) {
			
			myBuffer->Graphics->Clear(Color::White);
			ballsManager->draw(myBuffer);
			myBuffer->Render();
		}
		private: System::Void tickTimer_Tick(System::Object^ sender, System::EventArgs^ e) {
			ballsManager->move();
		}
	};
}
