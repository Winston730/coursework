#include "LogUpForm.h"
#include "WorkForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	//������ ������ �����
	Keyboardsimulator::LogUpForm form;
	Application::Run(% form);
}

System::Void Keyboardsimulator::LogUpForm::����������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	MessageBox::Show("��������� ������������� ��� �������� ������ � �����������!","���������� � ���������!");
}

System::Void Keyboardsimulator::LogUpForm::�����ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	Application::Exit();
}

System::Void Keyboardsimulator::LogUpForm::buttonStart_Click(System::Object^ sender, System::EventArgs^ e)
{
	//�������� ����� � ������ ���������
	String^ name = textBoxName->Text;
	if (name == "") {
		MessageBox::Show("������� ��� ������������!", "��������!");
		return;
	}

	int mode = checkedListBox->SelectedIndex;
	if (mode == -1) {
		MessageBox::Show("�������� ���������!", "��������!");
		return;
	}

	//������� ����� � �������� ���������
	WorkForm^ form = gcnew WorkForm();
	form->name = name;
	form->mode = mode;
	form->Show();
	this->Hide();

	return System::Void();
}
