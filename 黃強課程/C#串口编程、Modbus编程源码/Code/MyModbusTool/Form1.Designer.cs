namespace MyModbusTool
{
    partial class Form1
    {
        /// <summary>
        /// 必需的设计器变量。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 清理所有正在使用的资源。
        /// </summary>
        /// <param name="disposing">如果应释放托管资源，为 true；否则为 false。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows 窗体设计器生成的代码

        /// <summary>
        /// 设计器支持所需的方法 - 不要修改
        /// 使用代码编辑器修改此方法的内容。
        /// </summary>
        private void InitializeComponent()
        {
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.radioButtonAscii = new System.Windows.Forms.RadioButton();
            this.radioButtonRTU = new System.Windows.Forms.RadioButton();
            this.button16 = new System.Windows.Forms.Button();
            this.button06 = new System.Windows.Forms.Button();
            this.button15 = new System.Windows.Forms.Button();
            this.button01 = new System.Windows.Forms.Button();
            this.button03 = new System.Windows.Forms.Button();
            this.dataGridView1 = new System.Windows.Forms.DataGridView();
            this.buttonConnect = new System.Windows.Forms.Button();
            this.textBoxAddr = new System.Windows.Forms.TextBox();
            this.textBoxPort = new System.Windows.Forms.TextBox();
            this.label4 = new System.Windows.Forms.Label();
            this.textBoxIP_COM = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.comboBoxType = new System.Windows.Forms.ComboBox();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.radioButtonAscii_2 = new System.Windows.Forms.RadioButton();
            this.textBoxLog = new System.Windows.Forms.TextBox();
            this.radioButtonRTU_2 = new System.Windows.Forms.RadioButton();
            this.textBoxAddr_2 = new System.Windows.Forms.TextBox();
            this.label8 = new System.Windows.Forms.Label();
            this.comboBoxType_2 = new System.Windows.Forms.ComboBox();
            this.label5 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.dataGridView2 = new System.Windows.Forms.DataGridView();
            this.label7 = new System.Windows.Forms.Label();
            this.textBoxIP_COM_2 = new System.Windows.Forms.TextBox();
            this.textBoxPort_2 = new System.Windows.Forms.TextBox();
            this.label9 = new System.Windows.Forms.Label();
            this.buttonRefresh = new System.Windows.Forms.Button();
            this.buttonStart = new System.Windows.Forms.Button();
            this.comboBoxTable = new System.Windows.Forms.ComboBox();
            this.groupBox1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).BeginInit();
            this.groupBox2.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView2)).BeginInit();
            this.SuspendLayout();
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.radioButtonAscii);
            this.groupBox1.Controls.Add(this.radioButtonRTU);
            this.groupBox1.Controls.Add(this.button16);
            this.groupBox1.Controls.Add(this.button06);
            this.groupBox1.Controls.Add(this.button15);
            this.groupBox1.Controls.Add(this.button01);
            this.groupBox1.Controls.Add(this.button03);
            this.groupBox1.Controls.Add(this.dataGridView1);
            this.groupBox1.Controls.Add(this.buttonConnect);
            this.groupBox1.Controls.Add(this.textBoxAddr);
            this.groupBox1.Controls.Add(this.textBoxPort);
            this.groupBox1.Controls.Add(this.label4);
            this.groupBox1.Controls.Add(this.textBoxIP_COM);
            this.groupBox1.Controls.Add(this.label3);
            this.groupBox1.Controls.Add(this.comboBoxType);
            this.groupBox1.Controls.Add(this.label2);
            this.groupBox1.Controls.Add(this.label1);
            this.groupBox1.Location = new System.Drawing.Point(13, 5);
            this.groupBox1.Margin = new System.Windows.Forms.Padding(4);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Padding = new System.Windows.Forms.Padding(4);
            this.groupBox1.Size = new System.Drawing.Size(593, 690);
            this.groupBox1.TabIndex = 0;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Master";
            // 
            // radioButtonAscii
            // 
            this.radioButtonAscii.AutoSize = true;
            this.radioButtonAscii.Location = new System.Drawing.Point(418, 124);
            this.radioButtonAscii.Name = "radioButtonAscii";
            this.radioButtonAscii.Size = new System.Drawing.Size(71, 28);
            this.radioButtonAscii.TabIndex = 6;
            this.radioButtonAscii.TabStop = true;
            this.radioButtonAscii.Text = "Ascii";
            this.radioButtonAscii.UseVisualStyleBackColor = true;
            // 
            // radioButtonRTU
            // 
            this.radioButtonRTU.AutoSize = true;
            this.radioButtonRTU.Location = new System.Drawing.Point(418, 96);
            this.radioButtonRTU.Name = "radioButtonRTU";
            this.radioButtonRTU.Size = new System.Drawing.Size(66, 28);
            this.radioButtonRTU.TabIndex = 6;
            this.radioButtonRTU.TabStop = true;
            this.radioButtonRTU.Text = "RTU";
            this.radioButtonRTU.UseVisualStyleBackColor = true;
            // 
            // button16
            // 
            this.button16.Location = new System.Drawing.Point(377, 552);
            this.button16.Name = "button16";
            this.button16.Size = new System.Drawing.Size(186, 36);
            this.button16.TabIndex = 5;
            this.button16.Text = "16写 多个保持寄存器";
            this.button16.UseVisualStyleBackColor = true;
            this.button16.Click += new System.EventHandler(this.button16_Click);
            // 
            // button06
            // 
            this.button06.Location = new System.Drawing.Point(377, 510);
            this.button06.Name = "button06";
            this.button06.Size = new System.Drawing.Size(186, 36);
            this.button06.TabIndex = 5;
            this.button06.Text = "06写 单个保持寄存器";
            this.button06.UseVisualStyleBackColor = true;
            this.button06.Click += new System.EventHandler(this.button06_Click);
            // 
            // button15
            // 
            this.button15.Location = new System.Drawing.Point(377, 636);
            this.button15.Name = "button15";
            this.button15.Size = new System.Drawing.Size(186, 36);
            this.button15.TabIndex = 5;
            this.button15.Text = "15写 多个线圈";
            this.button15.UseVisualStyleBackColor = true;
            this.button15.Click += new System.EventHandler(this.button15_Click);
            // 
            // button01
            // 
            this.button01.Location = new System.Drawing.Point(377, 594);
            this.button01.Name = "button01";
            this.button01.Size = new System.Drawing.Size(186, 36);
            this.button01.TabIndex = 5;
            this.button01.Text = "01读 多个线圈";
            this.button01.UseVisualStyleBackColor = true;
            this.button01.Click += new System.EventHandler(this.button01_Click);
            // 
            // button03
            // 
            this.button03.Location = new System.Drawing.Point(377, 468);
            this.button03.Name = "button03";
            this.button03.Size = new System.Drawing.Size(186, 36);
            this.button03.TabIndex = 5;
            this.button03.Text = "03读 保持寄存器";
            this.button03.UseVisualStyleBackColor = true;
            this.button03.Click += new System.EventHandler(this.button03_Click);
            // 
            // dataGridView1
            // 
            this.dataGridView1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView1.Location = new System.Drawing.Point(40, 161);
            this.dataGridView1.Name = "dataGridView1";
            this.dataGridView1.RowHeadersWidth = 51;
            this.dataGridView1.RowTemplate.Height = 27;
            this.dataGridView1.Size = new System.Drawing.Size(545, 296);
            this.dataGridView1.TabIndex = 4;
            // 
            // buttonConnect
            // 
            this.buttonConnect.Location = new System.Drawing.Point(421, 36);
            this.buttonConnect.Name = "buttonConnect";
            this.buttonConnect.Size = new System.Drawing.Size(142, 40);
            this.buttonConnect.TabIndex = 3;
            this.buttonConnect.Text = "连接";
            this.buttonConnect.UseVisualStyleBackColor = true;
            this.buttonConnect.Click += new System.EventHandler(this.buttonConnect_Click);
            // 
            // textBoxAddr
            // 
            this.textBoxAddr.Location = new System.Drawing.Point(136, 531);
            this.textBoxAddr.Name = "textBoxAddr";
            this.textBoxAddr.Size = new System.Drawing.Size(174, 31);
            this.textBoxAddr.TabIndex = 2;
            // 
            // textBoxPort
            // 
            this.textBoxPort.Location = new System.Drawing.Point(136, 121);
            this.textBoxPort.Name = "textBoxPort";
            this.textBoxPort.Size = new System.Drawing.Size(174, 31);
            this.textBoxPort.TabIndex = 2;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(36, 531);
            this.label4.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(82, 24);
            this.label4.TabIndex = 0;
            this.label4.Text = "从站地址";
            // 
            // textBoxIP_COM
            // 
            this.textBoxIP_COM.Location = new System.Drawing.Point(136, 78);
            this.textBoxIP_COM.Name = "textBoxIP_COM";
            this.textBoxIP_COM.Size = new System.Drawing.Size(174, 31);
            this.textBoxIP_COM.TabIndex = 2;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(36, 120);
            this.label3.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(46, 24);
            this.label3.TabIndex = 0;
            this.label3.Text = "端口";
            // 
            // comboBoxType
            // 
            this.comboBoxType.FormattingEnabled = true;
            this.comboBoxType.Location = new System.Drawing.Point(136, 33);
            this.comboBoxType.Name = "comboBoxType";
            this.comboBoxType.Size = new System.Drawing.Size(174, 32);
            this.comboBoxType.TabIndex = 1;
            this.comboBoxType.SelectedIndexChanged += new System.EventHandler(this.comboBoxType_SelectedIndexChanged);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(36, 78);
            this.label2.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(80, 24);
            this.label2.TabIndex = 0;
            this.label2.Text = "IP或串口";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(36, 33);
            this.label1.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(82, 24);
            this.label1.TabIndex = 0;
            this.label1.Text = "通讯方式";
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.radioButtonAscii_2);
            this.groupBox2.Controls.Add(this.textBoxLog);
            this.groupBox2.Controls.Add(this.radioButtonRTU_2);
            this.groupBox2.Controls.Add(this.textBoxAddr_2);
            this.groupBox2.Controls.Add(this.label8);
            this.groupBox2.Controls.Add(this.comboBoxType_2);
            this.groupBox2.Controls.Add(this.label5);
            this.groupBox2.Controls.Add(this.label6);
            this.groupBox2.Controls.Add(this.dataGridView2);
            this.groupBox2.Controls.Add(this.label7);
            this.groupBox2.Controls.Add(this.textBoxIP_COM_2);
            this.groupBox2.Controls.Add(this.textBoxPort_2);
            this.groupBox2.Controls.Add(this.label9);
            this.groupBox2.Controls.Add(this.buttonRefresh);
            this.groupBox2.Controls.Add(this.buttonStart);
            this.groupBox2.Controls.Add(this.comboBoxTable);
            this.groupBox2.Location = new System.Drawing.Point(614, 13);
            this.groupBox2.Margin = new System.Windows.Forms.Padding(4);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Padding = new System.Windows.Forms.Padding(4);
            this.groupBox2.Size = new System.Drawing.Size(630, 683);
            this.groupBox2.TabIndex = 0;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Slave";
            // 
            // radioButtonAscii_2
            // 
            this.radioButtonAscii_2.AutoSize = true;
            this.radioButtonAscii_2.Location = new System.Drawing.Point(333, 104);
            this.radioButtonAscii_2.Name = "radioButtonAscii_2";
            this.radioButtonAscii_2.Size = new System.Drawing.Size(71, 28);
            this.radioButtonAscii_2.TabIndex = 6;
            this.radioButtonAscii_2.TabStop = true;
            this.radioButtonAscii_2.Text = "Ascii";
            this.radioButtonAscii_2.UseVisualStyleBackColor = true;
            // 
            // textBoxLog
            // 
            this.textBoxLog.Location = new System.Drawing.Point(57, 552);
            this.textBoxLog.Multiline = true;
            this.textBoxLog.Name = "textBoxLog";
            this.textBoxLog.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.textBoxLog.Size = new System.Drawing.Size(546, 120);
            this.textBoxLog.TabIndex = 6;
            // 
            // radioButtonRTU_2
            // 
            this.radioButtonRTU_2.AutoSize = true;
            this.radioButtonRTU_2.Location = new System.Drawing.Point(333, 76);
            this.radioButtonRTU_2.Name = "radioButtonRTU_2";
            this.radioButtonRTU_2.Size = new System.Drawing.Size(66, 28);
            this.radioButtonRTU_2.TabIndex = 6;
            this.radioButtonRTU_2.TabStop = true;
            this.radioButtonRTU_2.Text = "RTU";
            this.radioButtonRTU_2.UseVisualStyleBackColor = true;
            // 
            // textBoxAddr_2
            // 
            this.textBoxAddr_2.Location = new System.Drawing.Point(429, 31);
            this.textBoxAddr_2.Name = "textBoxAddr_2";
            this.textBoxAddr_2.Size = new System.Drawing.Size(174, 31);
            this.textBoxAddr_2.TabIndex = 5;
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(329, 31);
            this.label8.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(82, 24);
            this.label8.TabIndex = 4;
            this.label8.Text = "从站地址";
            // 
            // comboBoxType_2
            // 
            this.comboBoxType_2.FormattingEnabled = true;
            this.comboBoxType_2.Location = new System.Drawing.Point(125, 28);
            this.comboBoxType_2.Name = "comboBoxType_2";
            this.comboBoxType_2.Size = new System.Drawing.Size(174, 32);
            this.comboBoxType_2.TabIndex = 1;
            this.comboBoxType_2.SelectedIndexChanged += new System.EventHandler(this.comboBoxType_2_SelectedIndexChanged);
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(25, 29);
            this.label5.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(82, 24);
            this.label5.TabIndex = 0;
            this.label5.Text = "通讯方式";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(25, 71);
            this.label6.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(80, 24);
            this.label6.TabIndex = 0;
            this.label6.Text = "IP或串口";
            // 
            // dataGridView2
            // 
            this.dataGridView2.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView2.Location = new System.Drawing.Point(57, 161);
            this.dataGridView2.Name = "dataGridView2";
            this.dataGridView2.RowHeadersWidth = 51;
            this.dataGridView2.RowTemplate.Height = 27;
            this.dataGridView2.Size = new System.Drawing.Size(545, 296);
            this.dataGridView2.TabIndex = 4;
            this.dataGridView2.CellEndEdit += new System.Windows.Forms.DataGridViewCellEventHandler(this.dataGridView2_CellEndEdit);
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(25, 112);
            this.label7.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(46, 24);
            this.label7.TabIndex = 0;
            this.label7.Text = "端口";
            // 
            // textBoxIP_COM_2
            // 
            this.textBoxIP_COM_2.Location = new System.Drawing.Point(125, 68);
            this.textBoxIP_COM_2.Name = "textBoxIP_COM_2";
            this.textBoxIP_COM_2.Size = new System.Drawing.Size(174, 31);
            this.textBoxIP_COM_2.TabIndex = 2;
            // 
            // textBoxPort_2
            // 
            this.textBoxPort_2.Location = new System.Drawing.Point(125, 108);
            this.textBoxPort_2.Name = "textBoxPort_2";
            this.textBoxPort_2.Size = new System.Drawing.Size(174, 31);
            this.textBoxPort_2.TabIndex = 2;
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Location = new System.Drawing.Point(41, 501);
            this.label9.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(64, 24);
            this.label9.TabIndex = 0;
            this.label9.Text = "表类型";
            // 
            // buttonRefresh
            // 
            this.buttonRefresh.Location = new System.Drawing.Point(429, 485);
            this.buttonRefresh.Name = "buttonRefresh";
            this.buttonRefresh.Size = new System.Drawing.Size(173, 40);
            this.buttonRefresh.TabIndex = 3;
            this.buttonRefresh.Text = "刷新";
            this.buttonRefresh.UseVisualStyleBackColor = true;
            this.buttonRefresh.Click += new System.EventHandler(this.buttonRefresh_Click);
            // 
            // buttonStart
            // 
            this.buttonStart.Location = new System.Drawing.Point(429, 76);
            this.buttonStart.Name = "buttonStart";
            this.buttonStart.Size = new System.Drawing.Size(173, 40);
            this.buttonStart.TabIndex = 3;
            this.buttonStart.Text = "开启";
            this.buttonStart.UseVisualStyleBackColor = true;
            this.buttonStart.Click += new System.EventHandler(this.buttonStart_Click);
            // 
            // comboBoxTable
            // 
            this.comboBoxTable.FormattingEnabled = true;
            this.comboBoxTable.Location = new System.Drawing.Point(125, 501);
            this.comboBoxTable.Name = "comboBoxTable";
            this.comboBoxTable.Size = new System.Drawing.Size(174, 32);
            this.comboBoxTable.TabIndex = 1;
            this.comboBoxTable.SelectedIndexChanged += new System.EventHandler(this.comboBoxTable_SelectedIndexChanged);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(11F, 24F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1261, 693);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBox1);
            this.Font = new System.Drawing.Font("微软雅黑", 10.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.Margin = new System.Windows.Forms.Padding(4);
            this.Name = "Form1";
            this.Text = "黄强老师的Modbus工具";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.Form1_FormClosing);
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).EndInit();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView2)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Button buttonConnect;
        private System.Windows.Forms.TextBox textBoxPort;
        private System.Windows.Forms.TextBox textBoxIP_COM;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.ComboBox comboBoxType;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.DataGridView dataGridView1;
        private System.Windows.Forms.Button button16;
        private System.Windows.Forms.Button button06;
        private System.Windows.Forms.Button button15;
        private System.Windows.Forms.Button button01;
        private System.Windows.Forms.Button button03;
        private System.Windows.Forms.TextBox textBoxAddr;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.TextBox textBoxLog;
        private System.Windows.Forms.TextBox textBoxAddr_2;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.ComboBox comboBoxType_2;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.DataGridView dataGridView2;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.TextBox textBoxIP_COM_2;
        private System.Windows.Forms.TextBox textBoxPort_2;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.Button buttonRefresh;
        private System.Windows.Forms.Button buttonStart;
        private System.Windows.Forms.ComboBox comboBoxTable;
        private System.Windows.Forms.RadioButton radioButtonAscii;
        private System.Windows.Forms.RadioButton radioButtonRTU;
        private System.Windows.Forms.RadioButton radioButtonAscii_2;
        private System.Windows.Forms.RadioButton radioButtonRTU_2;
    }
}

