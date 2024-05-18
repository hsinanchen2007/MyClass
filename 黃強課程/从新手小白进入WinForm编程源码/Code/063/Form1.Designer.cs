namespace _063
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
            this.circleButton1 = new MyNS.CircleButton();
            this.sexRadioButton1 = new SexRadioButton.SexRadioButton();
            this.SuspendLayout();
            // 
            // circleButton1
            // 
            this.circleButton1.BackColor = System.Drawing.Color.Red;
            this.circleButton1.Diameter = 195;
            this.circleButton1.FlatAppearance.BorderSize = 0;
            this.circleButton1.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.circleButton1.Location = new System.Drawing.Point(111, 36);
            this.circleButton1.Name = "circleButton1";
            this.circleButton1.Size = new System.Drawing.Size(195, 195);
            this.circleButton1.TabIndex = 0;
            this.circleButton1.Text = "circleButton1";
            this.circleButton1.UseVisualStyleBackColor = false;
            this.circleButton1.Click += new System.EventHandler(this.circleButton1_Click);
            // 
            // sexRadioButton1
            // 
            this.sexRadioButton1.Location = new System.Drawing.Point(372, 36);
            this.sexRadioButton1.Name = "sexRadioButton1";
            this.sexRadioButton1.Size = new System.Drawing.Size(373, 161);
            this.sexRadioButton1.TabIndex = 1;
            this.sexRadioButton1.SexRadioButtonClick += new SexRadioButton.SexRadioButtonHandler(this.sexRadioButton1_SexRadioButtonClick);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.sexRadioButton1);
            this.Controls.Add(this.circleButton1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);

        }

        #endregion

        private MyNS.CircleButton circleButton1;
        private SexRadioButton.SexRadioButton sexRadioButton1;
    }
}

