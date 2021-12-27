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
	//catch (const std::exception &ex){
	catch (Exception^ ex) {
		MessageBox::Show(gcnew String(ex->Message), "B³¹d", MessageBoxButtons::OK);
		exit(1);
	}

	//MessageBox::Show("c: " + values.getCount() + " s: " + values.getSpeed() + " w: " + values.getWidth() + " h: " + values.getHeight() + " r: " + (values.getRunApp() ? "t" : "f"), "Ok");

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

	//MessageBox::Show("c: " + settings->getCount() + " s: " + settings->getSpeed() + " w: " + settings->getWidth() + " h: " + settings->getHeight(), "Ok");

	delete settings;

	return 0;
}