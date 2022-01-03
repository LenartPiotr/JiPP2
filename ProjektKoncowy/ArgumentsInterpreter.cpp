#include "pch.h"
#include "ArgumentsInterpreter.h"
#include "RunSettings.h"

ArgumentsInterpreter::ArgumentsInterpreter(array<String^>^ arguments) :arguments(arguments) {}

ArgumentValues ArgumentsInterpreter::GetValues()
{
	ArgumentValues values = ArgumentValues::DefaultValues();
	int count = arguments->Length;
	int value;
	double dvalue; 
	for (int i = 0; i < count; i++) {
		String^ arg = arguments[i];
		if (arg == "-c" || arg == "--count") {
			if (i + 1 >= count) throw gcnew Exception("Brak wartoœci dla parametru " + arg);
			try {
				value = int::Parse(arguments[++i]);
				if (!RunSettings::countRange.isInRange(value)) throw gcnew Exception("Invalid value");
				values.setCount(value);
			}
			catch (System::Exception^ ex) {
				throw gcnew Exception("B³êdna wartoœæ parametru " + arg);
			}
		} else
		if (arg == "-s" || arg == "--speed") {
			if (i + 1 >= count) throw gcnew Exception("Brak wartoœci dla parametru " + arg);
			try {
				dvalue = double::Parse(arguments[++i]);
				if (!RunSettings::speedRange.isInRange(dvalue)) throw gcnew Exception("Invalid value");
				values.setSpeed(dvalue);
			}
			catch (System::Exception^ ex) {
				throw gcnew Exception("B³êdna wartoœæ parametru " + arg);
			}
		} else
		if (arg == "-w" || arg == "--width") {
			if (i + 1 >= count) throw gcnew Exception("Brak wartoœci dla parametru " + arg);
			try {
				value = int::Parse(arguments[++i]);
				if (!RunSettings::widthRange.isInRange(value)) throw gcnew Exception("Invalid value");
				values.setWidth(value);
			}
			catch (System::Exception^ ex) {
				throw gcnew Exception("B³êdna wartoœæ parametru " + arg);
			}
		} else
		if (arg == "-h" || arg == "--height") {
			if (i + 1 >= count) throw gcnew Exception("Brak wartoœci dla parametru " + arg);
			try {
				value = int::Parse(arguments[++i]);
				if (!RunSettings::heightRange.isInRange(value)) throw gcnew Exception("Invalid value");
				values.setHeight(value);
			}
			catch (System::Exception^ ex) {
				throw gcnew Exception("B³êdna wartoœæ parametru " + arg);
			}
		} else
		if (arg == "-r" || arg == "--run") {
			values.setRunApp(true);
		}
		else {
			throw gcnew Exception("Nieznany argument " + arg);
		}
	}
	return values;
}
