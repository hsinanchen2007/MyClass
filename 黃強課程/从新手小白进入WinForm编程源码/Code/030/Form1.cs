using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _030
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent(); 
        }

        //复选框被勾选或取消勾选才触发
        private void treeView1_AfterCheck(object sender, TreeViewEventArgs e)
        {
            //MessageBox.Show(e.Node.Text +  "  是否选中  "+ e.Node.Checked );

            String strSelects = "";

            //遍历第一层节点
            for( int i=0;i<treeView1.Nodes.Count;++i)
            {
                TreeNode node = treeView1.Nodes[i];

                if(node.Checked )
                {  //是否选中
                    strSelects += "  " + node.Text;
                }

                //遍历第二层节点
                for (int j = 0; j< node.Nodes.Count; ++j)
                {
                    TreeNode subNode = node.Nodes[j];
                    if (subNode.Checked)
                    { //是否选中
                        strSelects += "  " + subNode.Text;
                    }

                }
            }

            MessageBox.Show(strSelects);

        }

        //选中了节点就会触发
        private void treeView1_AfterSelect(object sender, TreeViewEventArgs e)
        {
            MessageBox.Show( "选中了"+e.Node.Text );
        }
    }
}
