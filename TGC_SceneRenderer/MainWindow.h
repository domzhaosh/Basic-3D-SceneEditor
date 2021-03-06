#pragma once
#include "Context/OpenGL.h"
#include "Utils/Logger.h"
#include "ConsoleWindow.h"

namespace TGC_SceneRenderer {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace OpenGLForm;
    using namespace Utils;

    /// <summary>
    /// Summary for Form1
    /// </summary>
    public ref class MainWindow : public System::Windows::Forms::Form {
        public:
            MainWindow(void)
            {
                InitializeComponent();
                // Pass Tool Label To Logger
                Utils::Logger::SetStatusLabel(this->statusStripLabel);
                // Setup OpenGL Render Context Inside a Panel
                System::Windows::Forms::Panel ^oglRenderPanel = this->OpenGLRenderPanel;
                OpenGL = gcnew COpenGL(oglRenderPanel, 0, 0, oglRenderPanel->ClientSize.Width, oglRenderPanel->ClientSize.Height);
                // Add OpenGL Info to Form Title
                this->Text += " (" + Utils::Logger::GetLastLog() + ")";
                // Other Components
                consoleWindow = gcnew ConsoleWindow();
                consoleWindow->Owner = this;
            }

        protected:
            /// <summary>
            /// Clean up any resources being used.
            /// </summary>
            ~MainWindow()
            {
                if (components) {
                    delete components;
                }
            }

        private:
            /// <summary>
            /// Required designer variable.
            /// </summary>
        private: OpenGLForm::COpenGL ^OpenGL;
        private: ConsoleWindow ^consoleWindow;
        private: System::Windows::Forms::MenuStrip  ^topMenuBar;



        private: System::Windows::Forms::ToolStripMenuItem  ^fileToolStripMenuItem;
        private: System::Windows::Forms::ToolStripMenuItem  ^newSceneToolStripMenuItem;
        private: System::Windows::Forms::ToolStripMenuItem  ^openSceneToolStripMenuItem;
        private: System::Windows::Forms::ToolStripMenuItem  ^saveSceneToolStripMenuItem;
        private: System::Windows::Forms::ToolStripMenuItem  ^exitToolStripMenuItem;
        private: System::Windows::Forms::ToolStripSeparator  ^toolStripSeparator1;
        private: System::Windows::Forms::ToolStripMenuItem  ^saveSceneAsToolStripMenuItem;
        private: System::Windows::Forms::ToolStripSeparator  ^toolStripSeparator2;
        private: System::Windows::Forms::ToolStripMenuItem  ^editToolStripMenuItem;
        private: System::Windows::Forms::ToolStripMenuItem  ^modelsToolStripMenuItem;
        private: System::Windows::Forms::ToolStripMenuItem  ^importModelToolStripMenuItem;
        private: System::Windows::Forms::ToolStripMenuItem  ^sceneObjectToolStripMenuItem;
        private: System::Windows::Forms::ToolStripMenuItem  ^createEmptyToolStripMenuItem;
        private: System::Windows::Forms::ToolStripMenuItem  ^windowToolStripMenuItem;
        private: System::Windows::Forms::ToolStripMenuItem  ^aboutToolStripMenuItem;
        private: System::Windows::Forms::OpenFileDialog  ^assetImportFileDialog;
        private: System::Windows::Forms::StatusStrip  ^statusStrip;

        private: System::Windows::Forms::ToolStripStatusLabel  ^statusStripLabel;
        private: System::Windows::Forms::ToolStripMenuItem  ^consoleToolStripMenuItem;
        private: System::Windows::Forms::Panel  ^OpenGLRenderPanel;
        private: System::Windows::Forms::ToolStripMenuItem  ^createOtherToolStripMenuItem;
        private: System::Windows::Forms::ToolStripMenuItem  ^cameraToolStripMenuItem;
        private: System::Windows::Forms::ToolStripMenuItem  ^lightToolStripMenuItem;
        private: System::Windows::Forms::ToolStripMenuItem  ^objectsToolStripMenuItem;





            System::ComponentModel::Container ^components;

            #pragma region Windows Form Designer generated code
            /// <summary>
            /// Required method for Designer support - do not modify
            /// the contents of this method with the code editor.
            /// </summary>
            void InitializeComponent(void)
            {
				this->topMenuBar = (gcnew System::Windows::Forms::MenuStrip());
				this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->newSceneToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->openSceneToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
				this->saveSceneToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->saveSceneAsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->toolStripSeparator2 = (gcnew System::Windows::Forms::ToolStripSeparator());
				this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->editToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->modelsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->importModelToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->sceneObjectToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->createEmptyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->createOtherToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->cameraToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->lightToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->windowToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->consoleToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->objectsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->assetImportFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
				this->statusStrip = (gcnew System::Windows::Forms::StatusStrip());
				this->statusStripLabel = (gcnew System::Windows::Forms::ToolStripStatusLabel());
				this->OpenGLRenderPanel = (gcnew System::Windows::Forms::Panel());
				this->topMenuBar->SuspendLayout();
				this->statusStrip->SuspendLayout();
				this->SuspendLayout();
				// 
				// topMenuBar
				// 
				this->topMenuBar->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {this->fileToolStripMenuItem, 
					this->editToolStripMenuItem, this->modelsToolStripMenuItem, this->sceneObjectToolStripMenuItem, this->windowToolStripMenuItem, 
					this->aboutToolStripMenuItem});
				this->topMenuBar->Location = System::Drawing::Point(0, 0);
				this->topMenuBar->Name = L"topMenuBar";
				this->topMenuBar->Size = System::Drawing::Size(944, 24);
				this->topMenuBar->TabIndex = 1;
				this->topMenuBar->Text = L"topMenu";
				// 
				// fileToolStripMenuItem
				// 
				this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(7) {this->newSceneToolStripMenuItem, 
					this->openSceneToolStripMenuItem, this->toolStripSeparator1, this->saveSceneToolStripMenuItem, this->saveSceneAsToolStripMenuItem, 
					this->toolStripSeparator2, this->exitToolStripMenuItem});
				this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
				this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
				this->fileToolStripMenuItem->Text = L"File";
				// 
				// newSceneToolStripMenuItem
				// 
				this->newSceneToolStripMenuItem->Name = L"newSceneToolStripMenuItem";
				this->newSceneToolStripMenuItem->Size = System::Drawing::Size(157, 22);
				this->newSceneToolStripMenuItem->Text = L"New Scene";
				// 
				// openSceneToolStripMenuItem
				// 
				this->openSceneToolStripMenuItem->Name = L"openSceneToolStripMenuItem";
				this->openSceneToolStripMenuItem->Size = System::Drawing::Size(157, 22);
				this->openSceneToolStripMenuItem->Text = L"Open Scene";
				// 
				// toolStripSeparator1
				// 
				this->toolStripSeparator1->Name = L"toolStripSeparator1";
				this->toolStripSeparator1->Size = System::Drawing::Size(154, 6);
				// 
				// saveSceneToolStripMenuItem
				// 
				this->saveSceneToolStripMenuItem->Name = L"saveSceneToolStripMenuItem";
				this->saveSceneToolStripMenuItem->Size = System::Drawing::Size(157, 22);
				this->saveSceneToolStripMenuItem->Text = L"Save Scene";
				// 
				// saveSceneAsToolStripMenuItem
				// 
				this->saveSceneAsToolStripMenuItem->Name = L"saveSceneAsToolStripMenuItem";
				this->saveSceneAsToolStripMenuItem->Size = System::Drawing::Size(157, 22);
				this->saveSceneAsToolStripMenuItem->Text = L"Save Scene As...";
				// 
				// toolStripSeparator2
				// 
				this->toolStripSeparator2->Name = L"toolStripSeparator2";
				this->toolStripSeparator2->Size = System::Drawing::Size(154, 6);
				// 
				// exitToolStripMenuItem
				// 
				this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
				this->exitToolStripMenuItem->ShowShortcutKeys = false;
				this->exitToolStripMenuItem->Size = System::Drawing::Size(157, 22);
				this->exitToolStripMenuItem->Text = L"Exit";
				// 
				// editToolStripMenuItem
				// 
				this->editToolStripMenuItem->Name = L"editToolStripMenuItem";
				this->editToolStripMenuItem->Size = System::Drawing::Size(39, 20);
				this->editToolStripMenuItem->Text = L"Edit";
				// 
				// modelsToolStripMenuItem
				// 
				this->modelsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->importModelToolStripMenuItem});
				this->modelsToolStripMenuItem->Name = L"modelsToolStripMenuItem";
				this->modelsToolStripMenuItem->Size = System::Drawing::Size(52, 20);
				this->modelsToolStripMenuItem->Text = L"Assets";
				// 
				// importModelToolStripMenuItem
				// 
				this->importModelToolStripMenuItem->Name = L"importModelToolStripMenuItem";
				this->importModelToolStripMenuItem->Size = System::Drawing::Size(168, 22);
				this->importModelToolStripMenuItem->Text = L"Import New Asset";
				// 
				// sceneObjectToolStripMenuItem
				// 
				this->sceneObjectToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->createEmptyToolStripMenuItem, 
					this->createOtherToolStripMenuItem});
				this->sceneObjectToolStripMenuItem->Name = L"sceneObjectToolStripMenuItem";
				this->sceneObjectToolStripMenuItem->Size = System::Drawing::Size(88, 20);
				this->sceneObjectToolStripMenuItem->Text = L"Scene Object";
				// 
				// createEmptyToolStripMenuItem
				// 
				this->createEmptyToolStripMenuItem->Name = L"createEmptyToolStripMenuItem";
				this->createEmptyToolStripMenuItem->Size = System::Drawing::Size(145, 22);
				this->createEmptyToolStripMenuItem->Text = L"Create Empty";
				// 
				// createOtherToolStripMenuItem
				// 
				this->createOtherToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->cameraToolStripMenuItem, 
					this->lightToolStripMenuItem});
				this->createOtherToolStripMenuItem->Name = L"createOtherToolStripMenuItem";
				this->createOtherToolStripMenuItem->Size = System::Drawing::Size(145, 22);
				this->createOtherToolStripMenuItem->Text = L"Create Other";
				// 
				// cameraToolStripMenuItem
				// 
				this->cameraToolStripMenuItem->Name = L"cameraToolStripMenuItem";
				this->cameraToolStripMenuItem->Size = System::Drawing::Size(115, 22);
				this->cameraToolStripMenuItem->Text = L"Camera";
				// 
				// lightToolStripMenuItem
				// 
				this->lightToolStripMenuItem->Name = L"lightToolStripMenuItem";
				this->lightToolStripMenuItem->Size = System::Drawing::Size(115, 22);
				this->lightToolStripMenuItem->Text = L"Light";
				// 
				// windowToolStripMenuItem
				// 
				this->windowToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->consoleToolStripMenuItem, 
					this->objectsToolStripMenuItem});
				this->windowToolStripMenuItem->Name = L"windowToolStripMenuItem";
				this->windowToolStripMenuItem->Size = System::Drawing::Size(63, 20);
				this->windowToolStripMenuItem->Text = L"Window";
				// 
				// consoleToolStripMenuItem
				// 
				this->consoleToolStripMenuItem->Name = L"consoleToolStripMenuItem";
				this->consoleToolStripMenuItem->Size = System::Drawing::Size(152, 22);
				this->consoleToolStripMenuItem->Text = L"Console";
				this->consoleToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::consoleToolStripMenuItem_Click);
				// 
				// objectsToolStripMenuItem
				// 
				this->objectsToolStripMenuItem->Name = L"objectsToolStripMenuItem";
				this->objectsToolStripMenuItem->Size = System::Drawing::Size(152, 22);
				this->objectsToolStripMenuItem->Text = L"Objects";
				// 
				// aboutToolStripMenuItem
				// 
				this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
				this->aboutToolStripMenuItem->Size = System::Drawing::Size(52, 20);
				this->aboutToolStripMenuItem->Text = L"About";
				// 
				// assetImportFileDialog
				// 
				this->assetImportFileDialog->FileName = L"assetImportFileDialog";
				// 
				// statusStrip
				// 
				this->statusStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->statusStripLabel});
				this->statusStrip->LayoutStyle = System::Windows::Forms::ToolStripLayoutStyle::Flow;
				this->statusStrip->Location = System::Drawing::Point(0, 483);
				this->statusStrip->Name = L"statusStrip";
				this->statusStrip->Size = System::Drawing::Size(944, 19);
				this->statusStrip->TabIndex = 2;
				this->statusStrip->Text = L"statusStrip1";
				// 
				// statusStripLabel
				// 
				this->statusStripLabel->AutoSize = false;
				this->statusStripLabel->Name = L"statusStripLabel";
				this->statusStripLabel->Size = System::Drawing::Size(500, 14);
				this->statusStripLabel->Text = L"Welcome";
				this->statusStripLabel->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
				// 
				// OpenGLRenderPanel
				// 
				this->OpenGLRenderPanel->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
				this->OpenGLRenderPanel->Dock = System::Windows::Forms::DockStyle::Fill;
				this->OpenGLRenderPanel->Location = System::Drawing::Point(0, 24);
				this->OpenGLRenderPanel->Margin = System::Windows::Forms::Padding(0);
				this->OpenGLRenderPanel->Name = L"OpenGLRenderPanel";
				this->OpenGLRenderPanel->Size = System::Drawing::Size(944, 459);
				this->OpenGLRenderPanel->TabIndex = 3;
				this->OpenGLRenderPanel->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainWindow::timer1_Tick);
				// 
				// MainWindow
				// 
				this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				this->ClientSize = System::Drawing::Size(944, 502);
				this->Controls->Add(this->OpenGLRenderPanel);
				this->Controls->Add(this->statusStrip);
				this->Controls->Add(this->topMenuBar);
				this->MainMenuStrip = this->topMenuBar;
				this->Name = L"MainWindow";
				this->Text = L"TCG - SCENE";
				this->topMenuBar->ResumeLayout(false);
				this->topMenuBar->PerformLayout();
				this->statusStrip->ResumeLayout(false);
				this->statusStrip->PerformLayout();
				this->ResumeLayout(false);
				this->PerformLayout();

			}
            #pragma endregion
        private: System::Void timer1_Tick(System::Object  ^sender, System::Windows::Forms::PaintEventArgs  ^e)
            {
                OpenGL->restartStopwatch();
                UNREFERENCED_PARAMETER(sender);
                UNREFERENCED_PARAMETER(e);
                OpenGL->render();
                OpenGL->swapOpenGLBuffers();
                // Invalidate To Create a Game Loop
                ((System::Windows::Forms::Panel ^)sender)->Invalidate();

                if (OpenGL->getTotalTime() == 0.0) {
                    this->Refresh();
                }
            }

        private: System::Void consoleToolStripMenuItem_Click(System::Object  ^sender, System::EventArgs  ^e)
            {
                if (consoleWindow->Visible) {
                    consoleWindow->Hide();
                } else {
                    consoleWindow->Show();
                }
            }
    };
}

