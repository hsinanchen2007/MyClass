using Modbus.Data;
using Modbus.Device;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO.Ports;
using System.Linq;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MyModbusTool
{
   
    public partial class Form1 : Form
    {

        //考虑代码的优美,使用父类的引用接收 子类的实例
        ModbusMaster master = null; //主站
        ModbusSlave slave = null;//从站


        //定义委托类型
        public delegate void LogDelegate(String str);

        //定义一个委托类型的变量
        public LogDelegate log;

        //定义一个成员方法
        public   void UpdateTextBoxLog(String str)
        {
            string time = DateTime.Now.ToString("HH:mm:ss.fff");

            //追加到日志末尾
            textBoxLog.AppendText(time + " :   "+str+"\r\n") ;

            //光标移动到末尾
            textBoxLog.SelectionStart =textBoxLog.Text.Length ;
            textBoxLog.ScrollToCaret() ;
        }

        public Form1()
        {
            InitializeComponent();

            //委托赋值(为了跨线程访问控件)
            log = UpdateTextBoxLog;

            //初始化主站界面
            InitMasterUI();
           //初始化从站界面
            InitSlaveUI();
        }


        public  void InitMasterUI()
        {
            //初始化modbus类型
            comboBoxType.Items.Add("SerialPort");
            comboBoxType.Items.Add("TCP");
            comboBoxType.Items.Add("UCP"); 
            comboBoxType.SelectedIndex = 0;

            //初始化表格
            dataGridView1.Columns.Add("Alias", "Alias");
            dataGridView1.Columns.Add("00000", "00000");
            dataGridView1.AllowUserToAddRows = false;
            dataGridView1.AllowUserToOrderColumns = false;
            dataGridView1.Columns[1].SortMode = DataGridViewColumnSortMode.NotSortable; 
            dataGridView1.RowHeadersWidth = 60;
            dataGridView1.AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode.Fill;

            for (int i = 0; i < 10; i++)
            {
                dataGridView1.Rows.Add();
                dataGridView1.Rows[i].HeaderCell.Value = i.ToString();
            }

            //从站地址
            textBoxAddr.Text = "1";
        }


        public void InitSlaveUI()
        {
            //初始化modbus类型
            comboBoxType_2.Items.Add("SerialPort");
            comboBoxType_2.Items.Add("TCP");
            comboBoxType_2.Items.Add("UCP");
            comboBoxType_2.SelectedIndex = 0;

            //初始化表格
            dataGridView2.Columns.Add("Alias", "Alias");
            dataGridView2.Columns.Add("00000", "00000");
            dataGridView2.AllowUserToAddRows = false;
            dataGridView2.AllowUserToOrderColumns = false;
            dataGridView2.Columns[1].SortMode = DataGridViewColumnSortMode.NotSortable;
            dataGridView2.RowHeadersWidth = 60;
            dataGridView2.AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode.Fill;

            for (int i = 0; i < 10; i++)
            {
                dataGridView2.Rows.Add();
                dataGridView2.Rows[i].HeaderCell.Value = i.ToString();
            }

            //从站地址
            textBoxAddr_2.Text = "1";

            //4种表类型
            comboBoxTable.Items.Add(ModbusDataType.HoldingRegister);//保持寄存器
            comboBoxTable.Items.Add(ModbusDataType.InputRegister);//输入寄存器
            comboBoxTable.Items.Add(ModbusDataType.Coil);//线圈
            comboBoxTable.Items.Add(ModbusDataType.Input);//离散输入

            comboBoxTable.SelectedIndex = 0;
        }

        private void comboBoxType_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (comboBoxType.SelectedIndex == 0)
            {//串口
                textBoxIP_COM.Text = "COM1";
                textBoxPort.Text = "";
                radioButtonRTU.Checked = true;
            }
            else 
            {//TCP或UDP
                textBoxIP_COM.Text = "127.0.0.1";
                textBoxPort.Text = "33333";
                radioButtonRTU.Checked = false;
                radioButtonAscii.Checked = false;
            }
        }

        private void comboBoxType_2_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (comboBoxType_2.SelectedIndex == 0)
            {//串口
                textBoxIP_COM_2.Text = "COM2";
                textBoxPort_2.Text = ""; 
                radioButtonRTU_2.Checked = true;
            }
            else
            {//TCP或UDP
                textBoxIP_COM_2.Text = "127.0.0.1";
                textBoxPort_2.Text = "33333";
                radioButtonRTU_2.Checked = false;
                radioButtonAscii_2.Checked = false;
            }
        }

        private void buttonConnect_Click(object sender, EventArgs e)
        {
             if( buttonConnect.Text == "连接")
            { //连接从站
                StartMaster();
            }
            else
            {
                StopMaster();
            }
        }

        private void StartMaster()
        {
             try
             {
                if (comboBoxType.SelectedIndex == 0)
                {
                    //开启modbus rtu 或者 modbus ascii
                    SerialPort sp = new SerialPort();
                    sp.PortName = textBoxIP_COM.Text;//串口名
                    sp.BaudRate = 9600;//波特率
                    sp.DataBits = 8; //数据位
                    sp.Parity = Parity.Even;//奇偶校验
                    sp.StopBits = StopBits.One;//停止位
                    sp.Open();

                    if(radioButtonRTU.Checked)
                    {
                        //modbus rtu 采用串口通讯
                        master = ModbusSerialMaster.CreateRtu(sp);
                    }
                    else
                    {    //modbus ascii 采用串口通讯
                        master = ModbusSerialMaster.CreateAscii(sp);
                    }
                  
                }
                else  if (comboBoxType.SelectedIndex == 1)
                {
                    string ip = textBoxIP_COM.Text;
                    int  port = int.Parse( textBoxPort.Text);
                    //构造TCP客户端
                    TcpClient  tcp = new TcpClient(ip,port);

                    //实例为Modbus TCP
                    master = ModbusIpMaster.CreateIp( tcp);
                }
                else
                {
                    string ip = textBoxIP_COM.Text;
                    int port = int.Parse(textBoxPort.Text);
                    //构造UDP客户端
                    UdpClient udp = new UdpClient(ip, port);

                    //实例为Modbus UDP
                    master = ModbusIpMaster.CreateIp(udp);
                }

                 
                master.Transport.ReadTimeout = 100; //读取超时时间ms
                master.Transport.WriteTimeout = 100; //写超时时间
                master.Transport.Retries = 3;//重试次数
                master.Transport.WaitToRetryMilliseconds = 100;//重试间隔时间

                buttonConnect.Text = "断开";
            }
            catch (Exception ex)
             {
                    MessageBox.Show("连接失败:"+ex.Message);    
            }
            
        
        }
        private void StopMaster()
        {
            //释放资源
            master.Dispose();
            master = null;

            buttonConnect.Text = "连接";
        }

        private void button03_Click(object sender, EventArgs e)
        {
            if (master == null) return;
            //03功能码，读取一个或多个保持寄存器的值

            try
            {
                byte slaveAddr = byte.Parse(textBoxAddr.Text);//从站地址
                ushort start = 0;//开始读取的地址
                ushort num = 10;//读取的数量
                ushort[] data = master.ReadHoldingRegisters(slaveAddr, start, num);

                //将读取的值显示在表格上
                for(int i = 0; i < data.Length; i++)
                {
                    dataGridView1.Rows[i].Cells[1].Value = data[i];
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show("03功能码失败：" + ex.Message);
            }
        

        }

        private void button06_Click(object sender, EventArgs e)
        {
            if (master == null) return;

            //06功能码，写一个保持寄存器的值
            try
            {
                byte slaveAddr = byte.Parse(textBoxAddr.Text);//从站地址
                ushort writeAddr = 9;//写入一个值的地址
                ushort value = 9999;//写入的值
                master.WriteSingleRegister(slaveAddr, writeAddr, value);
                 
            }
            catch(Exception ex)
            {
                MessageBox.Show("06功能码失败：" + ex.Message);
            }
        }

        private void button16_Click(object sender, EventArgs e)
        {
            if (master == null) return;

            //16功能码，写多个保持寄存器的值
            try
            {
                byte slaveAddr = byte.Parse(textBoxAddr.Text);//从站地址
                ushort start = 1; //写入的开始地址
                ushort[] data = { 22, 33, 44 };// 写入的值的数量、数据大小、数据的值
                master.WriteMultipleRegisters(slaveAddr, start, data);

            }
            catch (Exception ex)
            {
                MessageBox.Show("16功能码失败：" + ex.Message);
            }
        }

        private void button01_Click(object sender, EventArgs e)
        {
            if (master == null) return;
            //01功能码，读取一个或多个线圈的值（bool类型 on  、off  1、0）

            try
            {
                byte slaveAddr = byte.Parse(textBoxAddr.Text);//从站地址
                ushort start = 0;//开始读取的地址
                ushort num = 10;//读取的数量

                //线圈的值，就是bool值
                bool[] data = master.ReadCoils(slaveAddr, start, num);

                //将读取的值显示在表格上
                for (int i = 0; i < data.Length; i++)
                {
                    String v = "";
                    if(data[i] )
                    {
                        v = "1";
                    }
                    else
                    {
                        v = "0";
                    }
                    dataGridView1.Rows[i].Cells[1].Value =v ;
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show("01功能码失败：" + ex.Message);
            }

        }

        private void button15_Click(object sender, EventArgs e)
        {
            if (master == null) return;

            //15功能码，写多个线圈的值
            try
            {
                byte slaveAddr = byte.Parse(textBoxAddr.Text);//从站地址
                ushort start = 1; //写入的开始地址
                bool [] data = {  true,true,true };// 写入的值的数量、几个字节、数据的值
                master.WriteMultipleCoils(slaveAddr, start, data);

            }
            catch (Exception ex)
            {
                MessageBox.Show("15功能码失败：" + ex.Message);
            }
        }

        private void buttonStart_Click(object sender, EventArgs e)
        {
              if( buttonStart.Text == "开启")
              {
                StartSlave();
              }
            else
            {
                StopSlave();
            }
        }
        private void StartSlave()
        {

            try
            {
                //先获取从站地址
                byte slaveAddr = byte.Parse(textBoxAddr_2.Text);//从站地址

                if (comboBoxType_2.SelectedIndex == 0)
                {
                    //开启modbus rtu 或者 modbus ascii
                    SerialPort sp = new SerialPort();
                    sp.PortName = textBoxIP_COM_2.Text;//串口名
                    sp.BaudRate = 9600;//波特率
                    sp.DataBits = 8; //数据位
                    sp.Parity = Parity.Even;//奇偶校验
                    sp.StopBits = StopBits.One;//停止位
                    sp.Open();

                    if (radioButtonRTU_2.Checked)
                    {
                        //modbus rtu 采用串口通讯
                        slave = ModbusSerialSlave.CreateRtu(slaveAddr, sp);
                    }
                    else
                    {    //modbus ascii 采用串口通讯
                        slave = ModbusSerialSlave.CreateAscii(slaveAddr, sp);
                    }

                }
                else if (comboBoxType_2.SelectedIndex == 1)
                {  //mosbus tcp

                    string ip = textBoxIP_COM_2.Text;
                    int port = int.Parse(textBoxPort_2.Text);
                    //构造TCP服务端，监听
                    TcpListener  tcp = new TcpListener( IPAddress.Parse(ip), port);
                    //创建Modbus TCP实例
                     slave =ModbusTcpSlave.CreateTcp(slaveAddr, tcp);
                }
                else
                { //mosbus udp

                    string ip = textBoxIP_COM_2.Text;
                    int port = int.Parse(textBoxPort_2.Text);
                    //构造UDP客户端 
                    IPEndPoint iep = new IPEndPoint(IPAddress.Parse(ip), port);
                    UdpClient  udp = new UdpClient(iep);
                    //创建Modbus UDP实例
                    slave = ModbusUdpSlave.CreateUdp(slaveAddr, udp);
                }

                //注意线程退出
                Thread thread = new Thread(  new ThreadStart(  
                    new Action(() => 
                    {
                        //开启监听，会开启一个循环
                        slave.Listen();
                    })
                    ));
                thread.Start();

                //订阅相关的事件（不订阅也不影响从站的相关功能）
                slave.ModbusSlaveRequestReceived +=
               new EventHandler<ModbusSlaveRequestEventArgs>((sender, e) =>
               {
                      this.BeginInvoke (log ,"ModbusSlaveRequestReceived")   ;
               });

                slave.WriteComplete += new EventHandler<ModbusSlaveRequestEventArgs>((sender, e) =>
                {
                    this.BeginInvoke(log, "WriteComplete");
                });

                slave.DataStore.DataStoreWrittenTo += new EventHandler<DataStoreEventArgs>((sender, e) =>
                {
                    this.BeginInvoke(log, "DataStore.DataStoreWrittenTo");
                });

                slave.DataStore.DataStoreReadFrom += new EventHandler<DataStoreEventArgs>((sender, e) =>
                {
                    this.BeginInvoke(log, "DataStore.DataStoreReadFrom ");
                });

                buttonStart.Text = "停止";
            }
            catch (Exception ex)
            {
                MessageBox.Show("开启失败:" + ex.Message);
            }
        }
        private void StopSlave()
        {
            slave.Dispose();

            buttonStart.Text = "开启";
        }

        private void dataGridView2_CellEndEdit(object sender, DataGridViewCellEventArgs e)
        {
            //获取当前表的类型
            String table = comboBoxTable.Text;

            //重点强调： DataStore 的索引是从1开始的，而非0

            //获取当前编辑的单元格的值
            object value =   dataGridView2.Rows[e.RowIndex].Cells[e.ColumnIndex].Value;
           if(value != null)
            { 
                String strV= value.ToString();

                ushort  v = ushort.Parse(strV); 

                //把字符串转换为枚举类型
                ModbusDataType type =
               (ModbusDataType)Enum.Parse(typeof(ModbusDataType), table);

                switch(type)
                {
                    case ModbusDataType.HoldingRegister:
                        //保持寄存器这张表（可读写）,ushort 类型
                        slave.DataStore.HoldingRegisters[e.RowIndex+1] = v; 
                        break;

                    case ModbusDataType.InputRegister:
                        //输入寄存器这张表（对主站而言，只读）,ushort 类型
                        slave.DataStore.InputRegisters[e.RowIndex + 1] = v; 
                        break;

                    case ModbusDataType.Coil:
                        //线圈寄存器这张表（可读写）,bool类型
                        slave.DataStore.CoilDiscretes[e.RowIndex + 1] = (v != 0);
                        break;

                    case ModbusDataType.Input:
                        //离散输入寄存器这张表（对主站而言，只读）,bool类型
                        slave.DataStore.InputDiscretes[e.RowIndex + 1] = (v != 0);
                        break;
                }

            }
        
        }

        private void comboBoxTable_SelectedIndexChanged(object sender, EventArgs e)
        {
            if(slave == null) return;

            //获取当前表的类型
            String table = comboBoxTable.Text;

            //把字符串转换为枚举类型
            ModbusDataType type =
           (ModbusDataType)Enum.Parse(typeof(ModbusDataType), table);


            //把DataStore里面的值显示到界面上
            switch (type)
            {
                case ModbusDataType.HoldingRegister:
                    
                    for(int i = 0; i <10; i++)
                    {  //索引从1开始
                         dataGridView2.Rows[i].Cells[1].Value 
                            = slave.DataStore.HoldingRegisters[i+1];
                    } 

                    break;

                case ModbusDataType.InputRegister:

                    for (int i = 0; i < 10; i++)
                    {  //索引从1开始
                        dataGridView2.Rows[i].Cells[1].Value
                           = slave.DataStore.InputRegisters[i + 1];
                    }

                    break;

                case ModbusDataType.Coil:

                    for (int i = 0; i < 10; i++)
                    {  //索引从1开始

                        bool  b = slave.DataStore.CoilDiscretes[i + 1];
                        String strV = "";
                        if(b)
                        {
                            strV = "1";
                        }
                        else
                        {
                            strV = "0";
                        }
                        dataGridView2.Rows[i].Cells[1].Value = strV;
                    }

                    break;

                case ModbusDataType.Input:

                    for (int i = 0; i < 10; i++)
                    {  //索引从1开始

                        bool b = slave.DataStore.InputDiscretes[i + 1];
                        String strV = "";
                        if (b)
                        {
                            strV = "1";
                        }
                        else
                        {
                            strV = "0";
                        }
                        dataGridView2.Rows[i].Cells[1].Value = strV;
                    }


                    break;
            }

        }

        private void buttonRefresh_Click(object sender, EventArgs e)
        {
            //直接调用
            comboBoxTable_SelectedIndexChanged(null,null);
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        { 
              //关闭两个Modbus实例
                if (master != null)
                {
                    master.Dispose();
                }

                if (slave != null)
                {
                    slave.Dispose();
                } 
        }
    }
}
