using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab08
{
   class Program
    {
        public class Basket
        {
            public List<Product> products = null;
            public int maxWeight;
            public int maxCost;

            public Basket(int maxW)
            {
                maxWeight = maxW;
            }

            public void getShowBasket()
            {
                Console.WriteLine("Ваша корзина:");
                foreach (var product in products)
                {
                    Console.WriteLine("================================");
                    Console.WriteLine(product);
                }
                Console.WriteLine($"================================\nМаксимальная цена товаров:{maxCost}\nОбщий вес товаров:{maxWeight}\n================================");
            }
            public void getAnalisis(List<Product> items)
            {
                if (items.Count > 0)
                    if (products == null)
                    {
                        if (getSumWeigth(items) <= maxWeight)
                        {
                            products = items;
                            maxCost = getSumCost(items);
                        }
                    }
                    else
                    {
                        if (getSumWeigth(items) <= maxWeight && getSumCost(items) > maxCost)
                        {
                            products = items;
                            maxCost = getSumCost(items);
                        }
                    }

                for (int i = 0; i < items.Count; i++)
                {
                    List<Product> newSet = new List<Product>(items);

                    newSet.RemoveAt(i);

                    getAnalisis(newSet);
                }

                
            }

            private int getSumWeigth(List<Product> items)
            {
                int sumW = 0;

                foreach (Product i in items)
                {
                    sumW += i._weight;
                }

                return sumW;
            }

            private int getSumCost(List<Product> items)
            {
                int sumPrice = 0;

                foreach (Product i in items)
                {
                    sumPrice += i._price;
                }

                return sumPrice;
            }

        }
        public class Product
        {
            public string _name;
            public int _price;
            public int _weight;
            public string Name
            {
                get { return _name; }
            }
            public int Price
            {
                get { return _price; }
            }
            public int Weight
            {
                get { return _weight; }
            }
            public Product(string name, int price, int weight)
            {
                _name = name;
                _price = price;
                _weight = weight;
            }
            public override string ToString()
            {
                string str = $"\nНазвание:{_name}, цена:{_price}, вес:{_weight}\n";
                return str;
            }
        }

        static void Main()
        {
            List<Product> list = new List<Product>();
            //Console.WriteLine("Введите количество продуктов");
            //int n = Convert.ToInt32(Console.ReadLine());
            //for(int i = 0; i < n; i++)
            //{
            //    Console.WriteLine("Напишите через пробел название товара, цену товара, его вес");
            //    string temp = Console.ReadLine();
            //    string[] tempS = temp.Split(' ');
            //    list.Add(new Product(tempS[0], Convert.ToInt32(tempS[1]), Convert.ToInt32(tempS[2])));
                
            //}
            Product i1 = new Product("Мясо", 600, 1);
            Product i2 = new Product("Чипсы", 5000, 2);
            Product i3 = new Product("Аптечка", 1500, 4);
            Product i4 = new Product("Ноутбук", 40000, 5);
            Product i5 = new Product("Программист", 500, 3);
            list.Add(i1);list.Add(i2);list.Add(i3);list.Add(i4);list.Add(i5);
            Console.WriteLine("Введите вместимость корзины");
            int temp2 = Convert.ToInt32(Console.ReadLine());
            Basket prov = new Basket(temp2);
            prov.getAnalisis(list);
            prov.getShowBasket();

        }
    }
}
