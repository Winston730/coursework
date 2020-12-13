#include "WorkForm.h"
#include "LogUpForm.h"
#include "Functions.h"

#include <fstream>
#include <string>

System::Void Keyboardsimulator::WorkForm::�����ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (start) {
		if (!complete) {
			if (MessageBox::Show("���� ��� �� ��������!\n��� ������ ��������� �����������.\n��������� �����?", "��������!", MessageBoxButtons::YesNo) == Windows::Forms::DialogResult::Yes) {
				//��������� ���������
				SaveResult();

				//������� �����
				LogUpForm^ form = gcnew LogUpForm();
				form->Show();
				this->Hide();
			}
		}
		else {
			//������� �����
			LogUpForm^ form = gcnew LogUpForm();
			form->Show();
			this->Hide();
		}
	}
	else {
		//������� �����
		LogUpForm^ form = gcnew LogUpForm();
		form->Show();
		this->Hide();
	}
}

System::Void Keyboardsimulator::WorkForm::����������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	MessageBox::Show("��������� ������������� ��� �������� ������ � �����������!", "���������� � ���������!");
}

System::Void Keyboardsimulator::WorkForm::�����ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (start) {
		if (!complete) {
			if (MessageBox::Show("���� ��� �� ��������!\n��� ������ ��������� �����������.\n�����?", "��������!", MessageBoxButtons::YesNo) == Windows::Forms::DialogResult::Yes) {
				//��������� ���������
				SaveResult();

				//�����
				Application::Exit();
			}
		}
		else {
			//�����
			Application::Exit();
		}
	}
	else {
		//�����
		Application::Exit();
	}
}

System::Void Keyboardsimulator::WorkForm::buttonStart_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (!start) {
		start = true;
		timer->Start();

		ResetParam();//�������� ���������

		ShowWords();//���������� ����� ��� �����
	}
	else
	{
		if (MessageBox::Show("���� ������� � �� ��������!\n��� ����������� ��������� �����������.\n�������������?", "��������!", MessageBoxButtons::YesNo) == Windows::Forms::DialogResult::Yes) {
			//��������� ���������
			SaveResult();

			//�����
			ResetParam();//�������� ���������
		}
	}
}

System::Void Keyboardsimulator::WorkForm::buttonNext_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (complete) {
		MessageBox::Show("���� ��� ��������!\n������� �����!", "��������!");
		return;
	}

	//��������
	Check();
	
	ShowWords();//���������� ����� ��� �����
}

System::Void Keyboardsimulator::WorkForm::buttonComplete_Click(System::Object^ sender, System::EventArgs^ e)
{
	timer->Stop();

	//��������
	Check();

	//���������� ����������
	SaveResult();

	complete = true;
	start = false;
}

System::Void Keyboardsimulator::WorkForm::WorkForm_Load(System::Object^ sender, System::EventArgs^ e)
{
	//��������� �����
	LoadData();

	MessageBox::Show("��� ������ ������� - ������\n��� �������� ����� ������� - ����������\n��� ���������� ������� - ���������","��������!");
}

void Keyboardsimulator::WorkForm::Update(System::Object^ sender, System::EventArgs^ e)
{
	time++;

	labelTimer->Text = "����� �����: " + Convert::ToString(time);
}

void Keyboardsimulator::WorkForm::SaveResult()
{
	//������� ����� ��� ������
	std::ofstream save("SaveResult.txt", std::ios::app);

	std::string _name;
	Convert_String_to_string(name, _name);

	//��������� ���������
	save << "��� ������������: " << _name << std::endl;

	save << "��������� ���������: ";
	if(mode == 0)
		save << "�������" << std::endl;
	else if(mode == 1)
		save << "�������" << std::endl;
	else 
		save << "�������" << std::endl;

	save << "���������� ������: " << in_total << std::endl;
	save << "���������� ������: " << correct_answers << std::endl;

	save << "����������� ����� �� ������ ���� (� ��������): " << std::endl;
	for (int i = 0; i < times.Count; i++) {
		save << i+1 << ": " << times[i] << std::endl;
	}
	save << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << std::endl;

	save.close();

	MessageBox::Show("��������� �������� � ����: SaveResult.txt","��������!");
}

void Keyboardsimulator::WorkForm::LoadData()
{
	//������� ����� ��� ������ 
	std::ifstream load("DataWords.txt");

	//�������� �����
	if (!load) {
		MessageBox::Show("������ �������� ����� �� �������!","������!");
		return;
	}

	//��������� ����������
	std::string bufs;
	String^ bufS;

	//��������� ��� �����
	while (!load.eof())
	{
		load >> bufs;
		bufS = Convert_string_to_String(bufs, bufS);
		words.Add(bufS);
	}

	MessageBox::Show("����� ��������� �� �����: DataWords.txt","��������!");
}

void Keyboardsimulator::WorkForm::ShowWords()
{
	//������� ������� �����
	textBoxOutput->Text = "";
	textBoxInput->Text = "";

	Random^ rand = gcnew Random();
	int count_words = 0;
	int index = 0;

	//��������� ������ ����
	if (mode == 0) {
		count_words = rand->Next(5, 10);//�������� ���������� ���������� ���� ������		
	}
	else if (mode == 1) {
		count_words = rand->Next(10, 15);//�������� ���������� ���������� ���� ������

	}
	else {
		count_words = rand->Next(15, 20);//�������� ���������� ���������� ���� ������
	}

	for (int i = 0; i < count_words; i++) {
		index = rand->Next(0, words.Count - 1);//�������� ���������� �����
		line_words += words[index];//���������� �����

		if (i < count_words - 1)
			line_words += " ";
	}

	//������� �����
	textBoxOutput->Text = line_words;
}

void Keyboardsimulator::WorkForm::ResetParam()
{
	complete = false;
	times.Clear();
	time = 0;
	correct_answers = 0;
	in_total = 0;
	line_words = "";
}

void Keyboardsimulator::WorkForm::Check()
{
	//���������� ��������� ������� �����
	times.Add(time);
	in_total++;

	//��������� ������ �����
	String^ input = textBoxInput->Text;

	//��������� ��������� � �������������� ������
	if (input == line_words) {
		correct_answers++;
	}

	time = 0;
	line_words = "";
}
