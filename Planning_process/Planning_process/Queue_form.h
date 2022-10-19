#pragma once
#include"System.h"

namespace Planning_process {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Queue_form
	/// </summary>
	public ref class Queue_form : public System::Windows::Forms::Form
	{
	public:
		Queue_form(My_system *my_system, int choice)
		{
			InitializeComponent();
			this->my_system = my_system;
			this->choice = choice;
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Queue_form()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^  dataGridView;
	protected:

	protected:






	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>
		My_system *my_system;
		int choice;

	private: System::Windows::Forms::DataGridViewTextBoxColumn^  ID_column;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Difficult_column;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Current_procent;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  State_column;
	private: System::Windows::Forms::Label^  close_label;





			 System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->dataGridView = (gcnew System::Windows::Forms::DataGridView());
			this->ID_column = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Difficult_column = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Current_procent = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->State_column = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->close_label = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView
			// 
			this->dataGridView->BackgroundColor = System::Drawing::SystemColors::Control;
			this->dataGridView->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->dataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->ID_column,
					this->Difficult_column, this->Current_procent, this->State_column
			});
			this->dataGridView->Location = System::Drawing::Point(1, 24);
			this->dataGridView->Name = L"dataGridView";
			this->dataGridView->ReadOnly = true;
			this->dataGridView->RowHeadersVisible = false;
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->dataGridView->RowsDefaultCellStyle = dataGridViewCellStyle2;
			this->dataGridView->Size = System::Drawing::Size(484, 492);
			this->dataGridView->TabIndex = 0;
			// 
			// ID_column
			// 
			this->ID_column->HeaderText = L"ID";
			this->ID_column->Name = L"ID_column";
			this->ID_column->ReadOnly = true;
			this->ID_column->Width = 80;
			// 
			// Difficult_column
			// 
			this->Difficult_column->HeaderText = L"Сложность";
			this->Difficult_column->Name = L"Difficult_column";
			this->Difficult_column->ReadOnly = true;
			this->Difficult_column->Width = 130;
			// 
			// Current_procent
			// 
			this->Current_procent->HeaderText = L"% завершения";
			this->Current_procent->Name = L"Current_procent";
			this->Current_procent->ReadOnly = true;
			this->Current_procent->Width = 140;
			// 
			// State_column
			// 
			this->State_column->HeaderText = L"Была ли блокировка";
			this->State_column->Name = L"State_column";
			this->State_column->ReadOnly = true;
			this->State_column->Width = 138;
			// 
			// close_label
			// 
			this->close_label->AutoSize = true;
			this->close_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->close_label->ForeColor = System::Drawing::Color::Red;
			this->close_label->Location = System::Drawing::Point(418, -3);
			this->close_label->Name = L"close_label";
			this->close_label->Size = System::Drawing::Size(77, 24);
			this->close_label->TabIndex = 1;
			this->close_label->Text = L"Скрыть";
			this->close_label->Click += gcnew System::EventHandler(this, &Queue_form::close_label_Click);
			// 
			// Queue_form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(497, 516);
			this->ControlBox = false;
			this->Controls->Add(this->close_label);
			this->Controls->Add(this->dataGridView);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"Queue_form";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Очередь";
			this->Load += gcnew System::EventHandler(this, &Queue_form::Queue_form_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void Queue_form_Load(System::Object^  sender, System::EventArgs^  e) {
			 time_tick();
			 dataGridView->AllowUserToAddRows = false;
}
public: void time_tick()
{
			dataGridView->AllowUserToAddRows = false;
			dataGridView->Rows->Clear();
			if (choice == 1)
			{
				this->Text = "Общая очередь задач";
				for (size_t i = 0; i < my_system->get_count_general_queue_tasks(); i++)
				{
					String ^state = my_system->get_task(i)->get_state();
					dataGridView->Rows->Add(Convert::ToString(my_system->get_task(i)->get_ID()),
						Convert::ToString(my_system->get_task(i)->get_difficult()),
						Convert::ToString(my_system->get_task(i)->get_current_procent()) + "%",
						state);
					delete state;
				}

			}
			else if (choice == 2)
			{
				this->Text = "Заблокированные задачи";
				dataGridView->Columns[3]->HeaderText = "Ост. время блокировки";
				for (size_t i = 0; i < my_system->get_count_block_tasks(); i++)
				{
					dataGridView->Rows->Add(Convert::ToString(my_system->get_block_task(i)->get_ID()),
						Convert::ToString(my_system->get_block_task(i)->get_difficult()),
						Convert::ToString(my_system->get_block_task(i)->get_current_procent()) + "%",
						Convert::ToString(my_system->get_block_task(i)->get_counter_block() + "сек"));
				}
			}
			else
			{
				this->Text = "Выполненные задачи";
				for (size_t i = 0; i < my_system->get_count_finish_tasks(); i++)
				{
					String ^state = my_system->get_finish_task(i)->get_state();
					dataGridView->Rows->Add(Convert::ToString(my_system->get_finish_task(i)->get_ID()),
						Convert::ToString(my_system->get_finish_task(i)->get_difficult()),
						Convert::ToString(my_system->get_finish_task(i)->get_current_procent()) + "%",
						state);
					delete state;
				}
			}
}
private: System::Void close_label_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Hide();
}
};
}
