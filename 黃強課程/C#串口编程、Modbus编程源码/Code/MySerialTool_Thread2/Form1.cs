﻿using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO.Ports;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MySerialTool
{
    public partial class Form1 : Form
    {
        //定义串口类的引用
        private SerialPort serial;

        //定义线程
        private Thread recvThread;

        //定时器
        private System.Windows.Forms.Timer timer;
        
        public Form1()
        {
            InitializeComponent();

            //初始化界面
            InitUI();

            //实例化定时器
            timer = new System.Windows.Forms.Timer();
            timer.Tick += Timer_Tick;

    
            //关掉跨线程检查
            CheckForIllegalCrossThreadCalls =false;

            //实例化串口对象
            serial = new SerialPort();
             
        }

        public  void StartRecvThread()
        {
            //实例化线程
            recvThread = new Thread(RecvThreadFun);

            recvThread.Start();
        }

        //线程处理函数
        private void RecvThreadFun()
        {
            //开启循环
            while (true)
            { 
                try
                { 
                    //没有数据，就会阻塞在这里
                    //直到有数据，才继续向下执行代码
                    int first =  serial.ReadByte();

                    //获取剩下可读取数据的长度
                    int len = serial.BytesToRead;
                     
                    byte[] left = new byte[len];
                    //读取剩下的内容
                    int nRead = serial.Read(left, 0, len);

                    //合并两份数据到data
                    byte  [] data = new byte[ 1+len];
                    data[0] = (byte)first;

                    for(int i = 0; i < len ; i++)
                    {
                        data[1 + i] = left[i];
                    }

                    //获取原有的文本
                    String strText = textBoxRecv.Text;

                   String strRecv = Encoding.UTF8.GetString(data);

                    String strTime = DateTime.Now.ToString("HH:mm:ss.fff : ");

                     //显示接收的数据
                     textBoxRecv.Text = strTime + strRecv + "\r\n" + strText;
                    
                }
                catch (Exception ex)
                 {
                    //当有异常的时候，跳出循环
                    break;
                } 
    
            }

          
        }

        public void InitUI()
        {
            //获取本机所有的串口名称
            string[]   ports =SerialPort.GetPortNames();
            foreach (string port in ports)
            {
                comboBoxName.Items.Add(port);
            }
            //默认选中第一个
            comboBoxName.SelectedIndex = 0;


            //波特率设置 
            string[] baudRates =
            { "9600","14400", "19200", "38400", "57600", "115200" };

            foreach (string  br in baudRates)
            {
                comboBoxBaudRate.Items.Add(br);
            }
            comboBoxBaudRate.SelectedIndex = 0;

            //数据位设置
            string[] dataBits = { "8", "7", "6", "5" };
            foreach (string bit in dataBits)
            {
                comboBoxDataBits.Items.Add(bit);
            }
            comboBoxDataBits.SelectedIndex = 0;

            //校验位设置
            Parity[] paritys =  { Parity.None, Parity.Odd, Parity.Even, Parity.Mark, Parity.Space};
            foreach (Parity parity in paritys)
            {
                comboBoxParity.Items.Add(parity);
            }
            comboBoxParity.SelectedIndex = 0;

            //停止位
            StopBits[] stopBits = { /*StopBits.None,*/ StopBits.One, StopBits.Two, StopBits.OnePointFive };
            foreach (StopBits  s in stopBits)
            {
                comboBoxStopBits.Items .Add(s);
            }
            comboBoxStopBits.SelectedIndex = 0;


        }

        private void buttonOpen_Click(object sender, EventArgs e)
        {

            if( buttonOpen.Text == "打开串口")
            {
                String PortName = comboBoxName.Text;
                String BaudRate = comboBoxBaudRate.Text;
                String DataBits = comboBoxDataBits.Text;
                String Parity = comboBoxParity.Text;
                String StopBits = comboBoxStopBits.Text;

                serial.PortName = PortName;
                serial.BaudRate = Convert.ToInt32(BaudRate);
                serial.DataBits = Convert.ToInt32(DataBits);
                //字符串转为枚举类型
                serial.Parity = (Parity)Enum.Parse(typeof(Parity), Parity);
                serial.StopBits = (StopBits)Enum.Parse(typeof(StopBits), StopBits);

                //参数配置好，打开串口

                try
                {
                    serial.Open();

                    if(serial.IsOpen)
                    {
                        //开启数据接收线程
                        StartRecvThread(); 
                    }

                    groupBox1.Enabled = false;
                    buttonOpen.Text = "关闭串口";

                }
                catch (Exception ex)
                {
                    MessageBox.Show(ex.Message);
                }

            }
            else
            {
                try
                {
                    serial.Close();
                    groupBox1.Enabled = true;
                    buttonOpen.Text = "打开串口";
                }
                catch (Exception ex)
                {
                    MessageBox.Show(ex.Message);
                }
            } 

        }

 
        private void buttonSend_Click(object sender, EventArgs e)
        {
            //串口打开才发送
            if(serial.IsOpen)
            {
                String  strSend = textBoxSend.Text;

                byte [] data = Encoding.UTF8.GetBytes(strSend);

                //发送数据到串口
                serial.Write(data, 0, data.Length);
            }
        }

        private void checkBox1_CheckStateChanged(object sender, EventArgs e)
        {
            if( checkBox1.Checked)
            {
                //定时器间隔事件
                try
                {
                    int interval = Convert.ToInt32(textBoxTime.Text);
                    timer.Interval = interval;
                    timer.Start();
                }
                catch (Exception ex)
                {
                    MessageBox.Show(ex.Message);    
                }
  
            }
            else
            {
                timer.Stop();
            }
        }


        //定时器事件响应的函数
        private void Timer_Tick(object sender, EventArgs e)
        {
            buttonSend_Click(null, null);
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            if( serial.IsOpen)
            {
                serial.Close();
            }
        }
    }



}
