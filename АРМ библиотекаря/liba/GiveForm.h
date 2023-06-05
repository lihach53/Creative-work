#pragma once
#include "Book.h"
#include "dateTimePicker.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <msclr\marshal_cppstd.h>
#include <filesystem>

namespace liba {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для GiveForm
	/// </summary>
	public ref class GiveForm : public System::Windows::Forms::Form
	{
	private: std::vector<std::string>* books;
		   dateTimePicker^ dtp = gcnew dateTimePicker();
		   std::vector<std::string>* readers;
	public:
		GiveForm(void)
		{
			InitializeComponent();
			books = new std::vector<std::string>;
			readers = new std::vector<std::string>;
			LoadListBook();
			LoadListPerson();
			give_groupBox2->Hide();
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~GiveForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::ListBox^ give_listBox;
	private: System::Windows::Forms::Button^ choose_button;
	private: System::Windows::Forms::GroupBox^ give_groupBox;
	private: System::Windows::Forms::GroupBox^ give_groupBox2;

	private: System::Windows::Forms::ListBox^ person_listBox;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ choose_button2;




	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(GiveForm::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->give_listBox = (gcnew System::Windows::Forms::ListBox());
			this->choose_button = (gcnew System::Windows::Forms::Button());
			this->give_groupBox = (gcnew System::Windows::Forms::GroupBox());
			this->give_groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->person_listBox = (gcnew System::Windows::Forms::ListBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->choose_button2 = (gcnew System::Windows::Forms::Button());
			this->give_groupBox->SuspendLayout();
			this->give_groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(114, 24);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(215, 16);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Выберите книгу для выдачи";
			// 
			// give_listBox
			// 
			this->give_listBox->FormattingEnabled = true;
			this->give_listBox->Location = System::Drawing::Point(13, 43);
			this->give_listBox->Name = L"give_listBox";
			this->give_listBox->Size = System::Drawing::Size(429, 225);
			this->give_listBox->TabIndex = 1;
			// 
			// choose_button
			// 
			this->choose_button->Location = System::Drawing::Point(13, 297);
			this->choose_button->Name = L"choose_button";
			this->choose_button->Size = System::Drawing::Size(429, 23);
			this->choose_button->TabIndex = 2;
			this->choose_button->Text = L"Выбрать";
			this->choose_button->UseVisualStyleBackColor = true;
			this->choose_button->Click += gcnew System::EventHandler(this, &GiveForm::choose_button_Click);
			// 
			// give_groupBox
			// 
			this->give_groupBox->Controls->Add(this->give_listBox);
			this->give_groupBox->Controls->Add(this->label1);
			this->give_groupBox->Controls->Add(this->choose_button);
			this->give_groupBox->Location = System::Drawing::Point(12, 12);
			this->give_groupBox->Name = L"give_groupBox";
			this->give_groupBox->Size = System::Drawing::Size(457, 326);
			this->give_groupBox->TabIndex = 4;
			this->give_groupBox->TabStop = false;
			this->give_groupBox->Text = L"Выдача книги";
			// 
			// give_groupBox2
			// 
			this->give_groupBox2->Controls->Add(this->person_listBox);
			this->give_groupBox2->Controls->Add(this->label2);
			this->give_groupBox2->Controls->Add(this->choose_button2);
			this->give_groupBox2->Location = System::Drawing::Point(12, 12);
			this->give_groupBox2->Name = L"give_groupBox2";
			this->give_groupBox2->Size = System::Drawing::Size(457, 326);
			this->give_groupBox2->TabIndex = 5;
			this->give_groupBox2->TabStop = false;
			this->give_groupBox2->Text = L"Выдача книги";
			// 
			// person_listBox
			// 
			this->person_listBox->BackColor = System::Drawing::SystemColors::Window;
			this->person_listBox->FormattingEnabled = true;
			this->person_listBox->Location = System::Drawing::Point(13, 43);
			this->person_listBox->Name = L"person_listBox";
			this->person_listBox->Size = System::Drawing::Size(429, 225);
			this->person_listBox->TabIndex = 1;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(147, 24);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(153, 16);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Выберите читателя";
			// 
			// choose_button2
			// 
			this->choose_button2->Location = System::Drawing::Point(13, 291);
			this->choose_button2->Name = L"choose_button2";
			this->choose_button2->Size = System::Drawing::Size(429, 23);
			this->choose_button2->TabIndex = 2;
			this->choose_button2->Text = L"Выбрать";
			this->choose_button2->UseVisualStyleBackColor = true;
			this->choose_button2->Click += gcnew System::EventHandler(this, &GiveForm::choose_button2_Click);
			// 
			// GiveForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(487, 357);
			this->Controls->Add(this->give_groupBox2);
			this->Controls->Add(this->give_groupBox);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"GiveForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"АРМ";
			this->give_groupBox->ResumeLayout(false);
			this->give_groupBox->PerformLayout();
			this->give_groupBox2->ResumeLayout(false);
			this->give_groupBox2->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: void LoadListBook()
	{
		if (std::filesystem::exists("database\\библиотека.txt"))
		{
			std::ifstream file("database\\библиотека.txt");

			std::string str = "";

			while (getline(file, str)) {
				(*books).push_back(str);
				give_listBox->Items->Add(msclr::interop::marshal_as<String^>(str));
			}
			file.close();
		}

	}

private: System::Void choose_button_Click(System::Object^ sender, System::EventArgs^ e) {
	int index = give_listBox->SelectedIndex;
	std::ofstream file("database\\buffer.txt");
	std::string str = (*books)[index];
	file << str;
	file.close();
	if (index >= 0 && index < (*books).size())
	{
		(*books).erase((*books).begin() + index);
		UpdateListBook();
	}
	std::ofstream log("database\\библиотека.txt");

	for (int i = 0; i < give_listBox->Items->Count; i++)
		log << msclr::interop::marshal_as<std::string>(give_listBox->Items[i]->ToString()) << std::endl;

	log.close();
	give_groupBox->Hide();
	give_groupBox2->Show();
}
	private: System::Void UpdateListBook() {
		give_listBox->Items->Clear();
		for (int i = 0; i < (*books).size(); i++)
			give_listBox->Items->Add(msclr::interop::marshal_as<String^>((*books)[i]));
	}
	private: System::Void UpdateListPerson() {
		person_listBox->Items->Clear();
		for (int i = 0; i < (*readers).size(); i++)
			person_listBox->Items->Add(msclr::interop::marshal_as<String^>((*readers)[i]));
	}
	private: void LoadListPerson()
	{
		if (std::filesystem::exists("database\\Читатели.txt"))
		{
			std::ifstream file("database\\Читатели.txt");

			std::string str = "";

			while (getline(file, str)) {
				(*readers).push_back(str);
				person_listBox->Items->Add(msclr::interop::marshal_as<String^>(str));
			}
			file.close();
		}
	}
private: System::Void choose_button2_Click(System::Object^ sender, System::EventArgs^ e) {
	int index = person_listBox->SelectedIndex;
	std::string str = (*readers)[index];
	std::string filename = "";
	std::wstring cyrillicDigits = L"0123456789";
	for (wchar_t c : str) {
		if (cyrillicDigits.find(c) != std::wstring::npos) {
			filename += c;
		}
	}
	std::string path = "users\\" + filename + ".txt";
	std::ifstream fileBuff("database\\buffer.txt");
	std::ofstream filePers;
	filePers.open(path, std::ios::app);
	std::string str1;
	getline(fileBuff, str1);
	filePers << str1 + ";";

	fileBuff.close();
	filePers.close();
	dtp->Show();
	dtp->Pathtxt(path);
	this->Hide();
}
};
}
