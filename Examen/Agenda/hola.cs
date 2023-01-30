using System;
class HelloWorld
{
    static void Main()
    {
        double Result;
        Console.WriteLine("Esta es una calcualora simple");
        Console.WriteLine("Ingrese la primera cifra: ");
        double Num_1 = Convert.ToDouble(Console.ReadLine());

        Console.WriteLine("Ingrese la segunda cifra: ");
        double Num_2 = Convert.ToDouble(Console.ReadLine());

        Console.WriteLine("Ingrese la operacion: ");
        string Op = Console.ReadLine();

    }
}