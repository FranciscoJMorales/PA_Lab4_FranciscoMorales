#pragma once
#include "Pokemon.h"
#include "Lista.h"
#include "Orden.h"

namespace PA_Lab4_FranciscoMorales_1223319 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Diagnostics;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  cargar_Btn;
	private: System::Windows::Forms::OpenFileDialog^  abrirArchivo;

	private: System::Windows::Forms::Button^  ordenar_Btn;
	private: System::Windows::Forms::GroupBox^  metodo_Gbx;
	private: System::Windows::Forms::RadioButton^  stupid_Rbtn;
	private: System::Windows::Forms::RadioButton^  quick_Rbtn;
	private: System::Windows::Forms::RadioButton^  bubble_Rbtn;
	private: System::Windows::Forms::GroupBox^  criterio_Gbx;
	private: System::Windows::Forms::RadioButton^  generacion_Rbtn;
	private: System::Windows::Forms::RadioButton^  id_Rbtn;
	private: System::Windows::Forms::RichTextBox^  listadoPokemon_Tbx;

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->cargar_Btn = (gcnew System::Windows::Forms::Button());
			this->abrirArchivo = (gcnew System::Windows::Forms::OpenFileDialog());
			this->ordenar_Btn = (gcnew System::Windows::Forms::Button());
			this->metodo_Gbx = (gcnew System::Windows::Forms::GroupBox());
			this->stupid_Rbtn = (gcnew System::Windows::Forms::RadioButton());
			this->quick_Rbtn = (gcnew System::Windows::Forms::RadioButton());
			this->bubble_Rbtn = (gcnew System::Windows::Forms::RadioButton());
			this->criterio_Gbx = (gcnew System::Windows::Forms::GroupBox());
			this->generacion_Rbtn = (gcnew System::Windows::Forms::RadioButton());
			this->id_Rbtn = (gcnew System::Windows::Forms::RadioButton());
			this->listadoPokemon_Tbx = (gcnew System::Windows::Forms::RichTextBox());
			this->metodo_Gbx->SuspendLayout();
			this->criterio_Gbx->SuspendLayout();
			this->SuspendLayout();
			// 
			// cargar_Btn
			// 
			this->cargar_Btn->Location = System::Drawing::Point(117, 23);
			this->cargar_Btn->Name = L"cargar_Btn";
			this->cargar_Btn->Size = System::Drawing::Size(86, 23);
			this->cargar_Btn->TabIndex = 0;
			this->cargar_Btn->Text = L"Cargar archivo";
			this->cargar_Btn->UseVisualStyleBackColor = true;
			this->cargar_Btn->Click += gcnew System::EventHandler(this, &MyForm::cargar_Btn_Click);
			// 
			// abrirArchivo
			// 
			this->abrirArchivo->DefaultExt = L"txt";
			this->abrirArchivo->FileName = L"Pokemon.txt";
			this->abrirArchivo->InitialDirectory = L"..//";
			// 
			// ordenar_Btn
			// 
			this->ordenar_Btn->Enabled = false;
			this->ordenar_Btn->Location = System::Drawing::Point(121, 207);
			this->ordenar_Btn->Name = L"ordenar_Btn";
			this->ordenar_Btn->Size = System::Drawing::Size(75, 23);
			this->ordenar_Btn->TabIndex = 1;
			this->ordenar_Btn->Text = L"Ordenar";
			this->ordenar_Btn->UseVisualStyleBackColor = true;
			this->ordenar_Btn->Click += gcnew System::EventHandler(this, &MyForm::ordenar_Btn_Click);
			// 
			// metodo_Gbx
			// 
			this->metodo_Gbx->Controls->Add(this->stupid_Rbtn);
			this->metodo_Gbx->Controls->Add(this->quick_Rbtn);
			this->metodo_Gbx->Controls->Add(this->bubble_Rbtn);
			this->metodo_Gbx->Location = System::Drawing::Point(12, 65);
			this->metodo_Gbx->Name = L"metodo_Gbx";
			this->metodo_Gbx->Size = System::Drawing::Size(143, 117);
			this->metodo_Gbx->TabIndex = 2;
			this->metodo_Gbx->TabStop = false;
			this->metodo_Gbx->Text = L"Método de ordenamiento:";
			// 
			// stupid_Rbtn
			// 
			this->stupid_Rbtn->AutoSize = true;
			this->stupid_Rbtn->Location = System::Drawing::Point(6, 87);
			this->stupid_Rbtn->Name = L"stupid_Rbtn";
			this->stupid_Rbtn->Size = System::Drawing::Size(77, 17);
			this->stupid_Rbtn->TabIndex = 2;
			this->stupid_Rbtn->Text = L"Stupid Sort";
			this->stupid_Rbtn->UseVisualStyleBackColor = true;
			// 
			// quick_Rbtn
			// 
			this->quick_Rbtn->AutoSize = true;
			this->quick_Rbtn->Location = System::Drawing::Point(6, 52);
			this->quick_Rbtn->Name = L"quick_Rbtn";
			this->quick_Rbtn->Size = System::Drawing::Size(75, 17);
			this->quick_Rbtn->TabIndex = 1;
			this->quick_Rbtn->Text = L"Quick Sort";
			this->quick_Rbtn->UseVisualStyleBackColor = true;
			// 
			// bubble_Rbtn
			// 
			this->bubble_Rbtn->AutoSize = true;
			this->bubble_Rbtn->Checked = true;
			this->bubble_Rbtn->Location = System::Drawing::Point(6, 19);
			this->bubble_Rbtn->Name = L"bubble_Rbtn";
			this->bubble_Rbtn->Size = System::Drawing::Size(80, 17);
			this->bubble_Rbtn->TabIndex = 0;
			this->bubble_Rbtn->TabStop = true;
			this->bubble_Rbtn->Text = L"Bubble Sort";
			this->bubble_Rbtn->UseVisualStyleBackColor = true;
			// 
			// criterio_Gbx
			// 
			this->criterio_Gbx->Controls->Add(this->generacion_Rbtn);
			this->criterio_Gbx->Controls->Add(this->id_Rbtn);
			this->criterio_Gbx->Location = System::Drawing::Point(161, 65);
			this->criterio_Gbx->Name = L"criterio_Gbx";
			this->criterio_Gbx->Size = System::Drawing::Size(159, 117);
			this->criterio_Gbx->TabIndex = 3;
			this->criterio_Gbx->TabStop = false;
			this->criterio_Gbx->Text = L"Ordenar por:";
			// 
			// generacion_Rbtn
			// 
			this->generacion_Rbtn->AutoSize = true;
			this->generacion_Rbtn->Location = System::Drawing::Point(6, 75);
			this->generacion_Rbtn->Name = L"generacion_Rbtn";
			this->generacion_Rbtn->Size = System::Drawing::Size(80, 17);
			this->generacion_Rbtn->TabIndex = 1;
			this->generacion_Rbtn->Text = L"Generación";
			this->generacion_Rbtn->UseVisualStyleBackColor = true;
			// 
			// id_Rbtn
			// 
			this->id_Rbtn->AutoSize = true;
			this->id_Rbtn->Checked = true;
			this->id_Rbtn->Location = System::Drawing::Point(6, 30);
			this->id_Rbtn->Name = L"id_Rbtn";
			this->id_Rbtn->Size = System::Drawing::Size(149, 17);
			this->id_Rbtn->TabIndex = 0;
			this->id_Rbtn->TabStop = true;
			this->id_Rbtn->Text = L"Número pokedex nacional";
			this->id_Rbtn->UseVisualStyleBackColor = true;
			// 
			// listadoPokemon_Tbx
			// 
			this->listadoPokemon_Tbx->Location = System::Drawing::Point(361, 23);
			this->listadoPokemon_Tbx->Name = L"listadoPokemon_Tbx";
			this->listadoPokemon_Tbx->Size = System::Drawing::Size(154, 207);
			this->listadoPokemon_Tbx->TabIndex = 4;
			this->listadoPokemon_Tbx->Text = L"";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(535, 252);
			this->Controls->Add(this->listadoPokemon_Tbx);
			this->Controls->Add(this->criterio_Gbx);
			this->Controls->Add(this->metodo_Gbx);
			this->Controls->Add(this->ordenar_Btn);
			this->Controls->Add(this->cargar_Btn);
			this->Name = L"MyForm";
			this->Text = L"Ordenamiento de pokémon";
			this->metodo_Gbx->ResumeLayout(false);
			this->metodo_Gbx->PerformLayout();
			this->criterio_Gbx->ResumeLayout(false);
			this->criterio_Gbx->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
		Orden *ordenamiento;

	private: System::Void cargar_Btn_Click(System::Object^  sender, System::EventArgs^  e) {
		try {
			ordenamiento = new Orden();
			abrirArchivo->FileName = "Pokemon.txt";
			abrirArchivo->ShowDialog();
			StreamReader^ streamReader = gcnew StreamReader(abrirArchivo->FileName);
			String^ contenidoArchivo = streamReader->ReadToEnd();
			streamReader->Close();
			listadoPokemon_Tbx->Text = contenidoArchivo;
			contenidoArchivo += "\r\n";
			int pos = contenidoArchivo->IndexOf("\r\n");
			while (pos > 0) {
				ordenamiento->Cargar(contenidoArchivo->Substring(0, pos));
				contenidoArchivo = contenidoArchivo->Remove(0, pos + 2);
				pos = contenidoArchivo->IndexOf("\r\n");
			}
			ordenar_Btn->Enabled = true;
		}
		catch (...) {
			System::Windows::Forms::MessageBox::Show("El formato de entrada o el archivo no es válido.", "Error");
		}
		
	}

	private: System::Void ordenar_Btn_Click(System::Object^  sender, System::EventArgs^  e) {
		Stopwatch ^tiempo = gcnew Stopwatch();
		String ^metodo = "";
		tiempo->Start();
		if (bubble_Rbtn->Checked) {
			ordenamiento->BubbleSort();
			metodo = "Bubble Sort";
		}
		else if (quick_Rbtn->Checked) {
			ordenamiento->QuickSort();
			metodo = "Quick Sort";
		}
		else if (stupid_Rbtn->Checked) {
			ordenamiento->StupidSort();
			metodo = "Stupid Sort";
		}
		tiempo->Stop();
		listadoPokemon_Tbx->Text = ordenamiento->String();
		System::Windows::Forms::MessageBox::Show("Tiempo en ordenar: " + tiempo->Elapsed, metodo);
	}
};
}
