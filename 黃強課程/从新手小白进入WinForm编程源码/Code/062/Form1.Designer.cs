namespace _062
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
            this.sexRadioButton1 = new SexRadioButton.SexRadioButton();
            this.SuspendLayout();
            // 
            // sexRadioButton1
            // 
            this.sexRadioButton1.Location = new System.Drawing.Point(100, 78);
            this.sexRadioButton1.Name = "sexRadioButton1";
            this.sexRadioButton1.Size = new System.Drawing.Size(346, 136);
            this.sexRadioButton1.TabIndex = 0;
            this.sexRadioButton1.SexRadioButtonClick += new SexRadioButton.SexRadioButtonHandler(this.sexRadioButton1_SexRadioButtonClick);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.sexRadioButton1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);

        }

        #endregion

        private SexRadioButton.SexRadioButton sexRadioButton1;
    }
}

