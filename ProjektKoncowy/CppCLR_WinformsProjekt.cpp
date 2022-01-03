#include "pch.h"
#include "Form1.h"
#include "Form2.h"
#include "ArgumentValues.h"
#include "ArgumentsInterpreter.h"

using namespace System;
using namespace cli;
using namespace System::Windows::Forms;
using namespace CppCLRWinformsProjekt;

[STAThread]
int main(array<String^>^ arg) {
	ArgumentsInterpreter interpreter(arg);
	ArgumentValues values;

	try {
		values = interpreter.GetValues();
	}
	catch (Exception^ ex) {
		MessageBox::Show(gcnew String(ex->Message), "B��d", MessageBoxButtons::OK);
		exit(1);
	}

	RunSettings* settings = new RunSettings(values);

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	if (!values.getRunApp()) {
		bool closeFormByButton = false;
		Form1^ settingsForm = gcnew Form1(settings, &closeFormByButton);
		Application::Run(settingsForm);
		if (!closeFormByButton) return 0;
	}

	Form2^ simulationForm = gcnew Form2(settings);
	Application::Run(simulationForm);
	
	delete settings;

	return 0;
}