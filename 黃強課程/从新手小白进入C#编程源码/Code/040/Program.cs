using Microsoft.CSharp;
using System;
using System.CodeDom.Compiler;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;

namespace _040
{
    class Program
    {
        static void Main(string[] args)
        {
            //创建编译器实例
            CSharpCodeProvider provider = new CSharpCodeProvider();

            //设置编译参数  
            CompilerParameters cp = new CompilerParameters();
            cp.GenerateExecutable = false;
            cp.GenerateInMemory = true;


            //创建类源代码  ，加上@，字符串可以分多行
            string source = @"  
            using System; 
            public class A
            {  
                public A(int id, string name)
                {
                     Console.WriteLine(  id + name);
                } 
            } 
	";


            //编译代码  
            CompilerResults result =
       provider.CompileAssemblyFromSource(cp, source);

            //获取编译后的程序集  
            Assembly assembly = result.CompiledAssembly;
            object[] paras = new object[] { 1, "小红" };
            object  o = assembly.CreateInstance("A",   true,  
                System.Reflection.BindingFlags.Default, null, paras, null, null);

            //相当于在运行时，动态定义了类A
            Type t = o.GetType();
            Console.WriteLine("动态定义的类"+ t);
        }
    }
}
