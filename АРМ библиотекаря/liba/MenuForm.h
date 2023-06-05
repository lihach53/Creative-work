#pragma once
#include "Form1.h"
#include "ReaderForm.h"
#include "GiveForm.h"
#include "AcceptForm.h"

namespace liba {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MenuForm
	/// </summary>
	public ref class MenuForm : public System::Windows::Forms::Form
	{
	private: 
		ReaderForm^ rf = gcnew ReaderForm();
		GiveForm^ gf = gcnew GiveForm();
		Form1^ f1 = gcnew Form1();
		AcceptForm^ af = gcnew AcceptForm();
	private: System::Windows::Forms::MonthCalendar^ monthCalendar1;


	public:
		MenuForm(void)
		{
			InitializeComponent();

		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MenuForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ContextMenuStrip^ contextMenuStrip1;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ складToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ читателиToolStripMenuItem;
	private: System::Windows::Forms::Button^ acceptbook_button;

	private: System::Windows::Forms::Button^ givebook_button;

	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Timer^ timer1;
	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MenuForm::typeid));
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->складToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->читателиToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->acceptbook_button = (gcnew System::Windows::Forms::Button());
			this->givebook_button = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->monthCalendar1 = (gcnew System::Windows::Forms::MonthCalendar());
			this->menuStrip1->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(61, 4);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->складToolStripMenuItem,
					this->читателиToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(220, 24);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// складToolStripMenuItem
			// 
			this->складToolStripMenuItem->Name = L"складToolStripMenuItem";
			this->складToolStripMenuItem->Size = System::Drawing::Size(52, 20);
			this->складToolStripMenuItem->Text = L"Склад";
			this->складToolStripMenuItem->Click += gcnew System::EventHandler(this, &MenuForm::складToolStripMenuItem_Click);
			// 
			// читателиToolStripMenuItem
			// 
			this->читателиToolStripMenuItem->Name = L"читателиToolStripMenuItem";
			this->читателиToolStripMenuItem->Size = System::Drawing::Size(70, 20);
			this->читателиToolStripMenuItem->Text = L"Читатели";
			this->читателиToolStripMenuItem->Click += gcnew System::EventHandler(this, &MenuForm::читателиToolStripMenuItem_Click);
			// 
			// acceptbook_button
			// 
			this->acceptbook_button->Location = System::Drawing::Point(16, 87);
			this->acceptbook_button->Name = L"acceptbook_button";
			this->acceptbook_button->Size = System::Drawing::Size(161, 34);
			this->acceptbook_button->TabIndex = 2;
			this->acceptbook_button->Text = L"Принять книгу";
			this->acceptbook_button->UseVisualStyleBackColor = true;
			this->acceptbook_button->Click += gcnew System::EventHandler(this, &MenuForm::acceptbook_button_Click);
			// 
			// givebook_button
			// 
			this->givebook_button->Location = System::Drawing::Point(16, 31);
			this->givebook_button->Name = L"givebook_button";
			this->givebook_button->Size = System::Drawing::Size(161, 34);
			this->givebook_button->TabIndex = 3;
			this->givebook_button->Text = L"Выдать книгу";
			this->givebook_button->UseVisualStyleBackColor = true;
			this->givebook_button->Click += gcnew System::EventHandler(this, &MenuForm::givebook_button_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->givebook_button);
			this->groupBox1->Controls->Add(this->acceptbook_button);
			this->groupBox1->Location = System::Drawing::Point(12, 42);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(196, 148);
			this->groupBox1->TabIndex = 4;
			this->groupBox1->TabStop = false;
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MenuForm::timer1_Tick);
			// 
			// monthCalendar1
			// 
			this->monthCalendar1->Location = System::Drawing::Point(22, 202);
			this->monthCalendar1->Name = L"monthCalendar1";
			this->monthCalendar1->TabIndex = 5;
			// 
			// MenuForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(220, 383);
			this->Controls->Add(this->monthCalendar1);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->menuStrip1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MenuForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"АРМ";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &MenuForm::MenuForm_FormClosed);
			this->Load += gcnew System::EventHandler(this, &MenuForm::MenuForm_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void складToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		f1 = gcnew Form1(); // создаем экземпляр формы Form1
		f1->Show(); //Открываем форму Form1
	}
	private: System::Void MenuForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void читателиToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	rf = gcnew ReaderForm();
	rf->Show();
}
private: System::Void givebook_button_Click(System::Object^ sender, System::EventArgs^ e) {
	gf = gcnew GiveForm();
	gf->Show();
}
private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
	if (rf->Visible || f1->Visible) {
		menuStrip1->Enabled = false;
		groupBox1->Enabled = false;
		monthCalendar1->Enabled = false;
	}
	else {
		menuStrip1->Enabled = true;
		groupBox1->Enabled = true;
		monthCalendar1->Enabled = true;
	}
}
private: System::Void acceptbook_button_Click(System::Object^ sender, System::EventArgs^ e) {
	af = gcnew AcceptForm();
	af->Show();
}
private: System::Void MenuForm_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
	Application::Exit();
}
};
}
