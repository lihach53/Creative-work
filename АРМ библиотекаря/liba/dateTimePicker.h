#pragma once
#include <Windows.h>
#include <msclr\marshal_cppstd.h>
#include <fstream>

namespace liba {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для dateTimePicker
	/// </summary>
	/// 
	
	static std::string Path;

	public ref class dateTimePicker : public System::Windows::Forms::Form
	{
	public:
		dateTimePicker(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~dateTimePicker()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker1;
	private: System::Windows::Forms::Button^ vybrat_button;
	private: System::Windows::Forms::Label^ label1;
	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(dateTimePicker::typeid));
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->vybrat_button = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Location = System::Drawing::Point(12, 28);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(230, 20);
			this->dateTimePicker1->TabIndex = 6;
			// 
			// vybrat_button
			// 
			this->vybrat_button->Location = System::Drawing::Point(25, 85);
			this->vybrat_button->Name = L"vybrat_button";
			this->vybrat_button->Size = System::Drawing::Size(200, 25);
			this->vybrat_button->TabIndex = 7;
			this->vybrat_button->Text = L"Выбрать";
			this->vybrat_button->UseVisualStyleBackColor = true;
			this->vybrat_button->Click += gcnew System::EventHandler(this, &dateTimePicker::vybrat_button_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(67, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(108, 15);
			this->label1->TabIndex = 8;
			this->label1->Text = L"Выберите дату";
			// 
			// dateTimePicker
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(254, 122);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->vybrat_button);
			this->Controls->Add(this->dateTimePicker1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"dateTimePicker";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"АРМ";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public: void Pathtxt(std::string put) {
		Path = put;
	}
	private: System::Void vybrat_button_Click(System::Object^ sender, System::EventArgs^ e) {
		DateTime selectedDate = dateTimePicker1->Value;
		String^ dateString = selectedDate.ToString();
		DateTime currentTime = DateTime::Now;
		TimeSpan difference = selectedDate - currentTime;
		MessageBox::Show("Книга выдана до " + dateString + "\n" + "Сдать через " + difference.Days + " дн." + difference.Hours + "ч." + difference.Minutes + "мин.", "Срок сдачи");
		String^ selectedString = selectedDate.ToString(); // Преобразование разницы в строку
		std::string differenceStdString = msclr::interop::marshal_as<std::string>(selectedString); // Преобразование String^ в std::string
		std::ofstream filedate;
		filedate.open(Path, std::ios::app);
		std::string str = differenceStdString + ";";
		filedate << str;
		filedate.close();
		this->Close();
	}
	};
}
