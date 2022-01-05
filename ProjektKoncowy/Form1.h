#pragma once
#include "IOException.h"
#include "RunSettings.h"

namespace CppCLRWinformsProjekt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Zusammenfassung für Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	private:
		RunSettings* settings;
		bool* closeFormByButton;
	public:
		Form1(RunSettings* settings, bool *closeFormByButton) : settings(settings), closeFormByButton(closeFormByButton)
		{
			InitializeComponent();
			inputCount->Minimum = RunSettings::countRange.getMinimum();
			inputCount->Maximum = RunSettings::countRange.getMaximum();
			inputSpeed->Minimum = Decimal(RunSettings::speedRange.getMinimum());
			inputSpeed->Maximum = Decimal(RunSettings::speedRange.getMaximum());
			inputWidth->Minimum = RunSettings::widthRange.getMinimum();
			inputWidth->Maximum = RunSettings::widthRange.getMaximum();
			inputHeight->Minimum = RunSettings::heightRange.getMinimum();
			inputHeight->Maximum = RunSettings::heightRange.getMaximum();
			inputCount->Value = settings->getCount();
			inputSpeed->Value = Decimal(settings->getSpeed());
			inputWidth->Value = settings->getWidth();
			inputHeight->Value = settings->getHeight();
		}
	protected:
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::NumericUpDown^ inputCount;
	private: System::Windows::Forms::NumericUpDown^ inputSpeed;
	private: System::Windows::Forms::NumericUpDown^ inputWidth;
	private: System::Windows::Forms::NumericUpDown^ inputHeight;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Button^ buttonRun;
	private: System::Windows::Forms::Button^ saveButton;
	private: System::Windows::Forms::Button^ readButton;
	private: System::ComponentModel::IContainer^ components;
	protected:

	private:

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->inputCount = (gcnew System::Windows::Forms::NumericUpDown());
			this->inputSpeed = (gcnew System::Windows::Forms::NumericUpDown());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->inputWidth = (gcnew System::Windows::Forms::NumericUpDown());
			this->inputHeight = (gcnew System::Windows::Forms::NumericUpDown());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->buttonRun = (gcnew System::Windows::Forms::Button());
			this->saveButton = (gcnew System::Windows::Forms::Button());
			this->readButton = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->inputCount))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->inputSpeed))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->inputWidth))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->inputHeight))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label1->Location = System::Drawing::Point(12, 37);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(49, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Iloœæ kul";
			// 
			// inputCount
			// 
			this->inputCount->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->inputCount->Location = System::Drawing::Point(86, 35);
			this->inputCount->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000, 0, 0, 0 });
			this->inputCount->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->inputCount->Name = L"inputCount";
			this->inputCount->Size = System::Drawing::Size(84, 22);
			this->inputCount->TabIndex = 1;
			this->inputCount->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			// 
			// inputSpeed
			// 
			this->inputSpeed->DecimalPlaces = 2;
			this->inputSpeed->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->inputSpeed->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 131072 });
			this->inputSpeed->Location = System::Drawing::Point(86, 63);
			this->inputSpeed->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000, 0, 0, 0 });
			this->inputSpeed->Name = L"inputSpeed";
			this->inputSpeed->Size = System::Drawing::Size(84, 22);
			this->inputSpeed->TabIndex = 2;
			this->inputSpeed->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1002, 0, 0, 131072 });
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label2->Location = System::Drawing::Point(12, 65);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(72, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Prêdkoœæ kul";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label3->Location = System::Drawing::Point(12, 93);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(58, 13);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Szerokoœæ";
			// 
			// inputWidth
			// 
			this->inputWidth->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->inputWidth->Location = System::Drawing::Point(86, 91);
			this->inputWidth->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000, 0, 0, 0 });
			this->inputWidth->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->inputWidth->Name = L"inputWidth";
			this->inputWidth->Size = System::Drawing::Size(84, 22);
			this->inputWidth->TabIndex = 5;
			this->inputWidth->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			// 
			// inputHeight
			// 
			this->inputHeight->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->inputHeight->Location = System::Drawing::Point(86, 119);
			this->inputHeight->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000, 0, 0, 0 });
			this->inputHeight->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->inputHeight->Name = L"inputHeight";
			this->inputHeight->Size = System::Drawing::Size(84, 22);
			this->inputHeight->TabIndex = 6;
			this->inputHeight->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label4->Location = System::Drawing::Point(12, 121);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(58, 13);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Wysokoœæ";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label5->Location = System::Drawing::Point(46, 9);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(86, 21);
			this->label5->TabIndex = 8;
			this->label5->Text = L"Ustawienia";
			// 
			// buttonRun
			// 
			this->buttonRun->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->buttonRun->Location = System::Drawing::Point(12, 176);
			this->buttonRun->Name = L"buttonRun";
			this->buttonRun->Size = System::Drawing::Size(158, 23);
			this->buttonRun->TabIndex = 9;
			this->buttonRun->Text = L"Symuluj";
			this->buttonRun->UseVisualStyleBackColor = true;
			this->buttonRun->Click += gcnew System::EventHandler(this, &Form1::buttonRun_Click);
			// 
			// saveButton
			// 
			this->saveButton->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->saveButton->Location = System::Drawing::Point(12, 147);
			this->saveButton->Name = L"saveButton";
			this->saveButton->Size = System::Drawing::Size(75, 23);
			this->saveButton->TabIndex = 10;
			this->saveButton->Text = L"Zapisz";
			this->saveButton->UseVisualStyleBackColor = true;
			this->saveButton->Click += gcnew System::EventHandler(this, &Form1::saveButton_Click);
			// 
			// readButton
			// 
			this->readButton->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->readButton->Location = System::Drawing::Point(95, 147);
			this->readButton->Name = L"readButton";
			this->readButton->Size = System::Drawing::Size(75, 23);
			this->readButton->TabIndex = 11;
			this->readButton->Text = L"Wczytaj";
			this->readButton->UseVisualStyleBackColor = true;
			this->readButton->Click += gcnew System::EventHandler(this, &Form1::readButton_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(182, 210);
			this->Controls->Add(this->readButton);
			this->Controls->Add(this->saveButton);
			this->Controls->Add(this->buttonRun);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->inputHeight);
			this->Controls->Add(this->inputWidth);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->inputSpeed);
			this->Controls->Add(this->inputCount);
			this->Controls->Add(this->label1);
			this->ForeColor = System::Drawing::SystemColors::ControlText;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"Form1";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Form1::Form1_FormClosed);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->inputCount))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->inputSpeed))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->inputWidth))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->inputHeight))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		#pragma endregion
	private:
		System::Void buttonRun_Click(System::Object^ sender, System::EventArgs^ e) {
			*closeFormByButton = true;
			Close();
		}
		System::Void Form1_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
			saveToSettings();
		}
		System::Void saveButton_Click(System::Object^ sender, System::EventArgs^ e) {
			saveToSettings();
			SaveFileDialog dialog;
			dialog.Filter = "bin files (*.bin)|*.bin|All files (*.*)|*.*";
			dialog.RestoreDirectory = true;
			if (dialog.ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				String^ filename = dialog.FileName;
				char* buffer = new char[filename->Length + 2];
				sprintf(buffer, "%s", filename);
				try {
					settings->save(buffer);
				}
				catch (IOException exception){
					MessageBox::Show(gcnew String(exception.what()), "IOException");
				}
				delete[] buffer;
			}
		}
		System::Void readButton_Click(System::Object^ sender, System::EventArgs^ e) {
			OpenFileDialog dialog;
			dialog.Filter = "bin files (*.bin)|*.bin|All files (*.*)|*.*";
			dialog.RestoreDirectory = true;
			if (dialog.ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				String^ filename = dialog.FileName;
				char* buffer = new char[filename->Length + 2];
				sprintf(buffer, "%s", filename);
				try {
					settings->read(buffer);
					if (RunSettings::countRange.isInRange(settings->getCount()) &&
						RunSettings::speedRange.isInRange(settings->getSpeed()) &&
						RunSettings::widthRange.isInRange(settings->getWidth()) &&
						RunSettings::heightRange.isInRange(settings->getHeight())) {
						inputCount->Value = settings->getCount();
						inputSpeed->Value = Decimal(settings->getSpeed());
						inputWidth->Value = settings->getWidth();
						inputHeight->Value = settings->getHeight();
					}
					else {
						saveToSettings();
						throw IOException("B³¹d wczytywania - nieprawid³owy plik");
					}
				}
				catch (IOException exception) {
					MessageBox::Show(gcnew String(exception.what()), "IOException");
				}
				delete[] buffer;
			}
		}
		void saveToSettings() {
			settings->setCount(RunSettings::countRange.getTheClosestValue(Decimal::ToInt32(inputCount->Value)));
			settings->setSpeed(RunSettings::speedRange.getTheClosestValue(Decimal::ToDouble(inputSpeed->Value)));
			settings->setWidth(RunSettings::widthRange.getTheClosestValue(Decimal::ToInt32(inputWidth->Value)));
			settings->setHeight(RunSettings::heightRange.getTheClosestValue(Decimal::ToInt32(inputHeight->Value)));
		}
	};
}
