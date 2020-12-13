#include "LogUpForm.h"
#include "WorkForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	//Запуск первой формы
	Keyboardsimulator::LogUpForm form;
	Application::Run(% form);
}

System::Void Keyboardsimulator::LogUpForm::оПрограммеToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	MessageBox::Show("Программа предназначена для обучения работы с клавиатурой!","Информация о программе!");
}

System::Void Keyboardsimulator::LogUpForm::выходToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	Application::Exit();
}

System::Void Keyboardsimulator::LogUpForm::buttonStart_Click(System::Object^ sender, System::EventArgs^ e)
{
	//Проверка ввода и выбора сложности
	String^ name = textBoxName->Text;
	if (name == "") {
		MessageBox::Show("Укажите имя пользователя!", "Внимание!");
		return;
	}

	int mode = checkedListBox->SelectedIndex;
	if (mode == -1) {
		MessageBox::Show("Выберите сложность!", "Внимание!");
		return;
	}

	//Создаем форму и передаем параметры
	WorkForm^ form = gcnew WorkForm();
	form->name = name;
	form->mode = mode;
	form->Show();
	this->Hide();

	return System::Void();
}
