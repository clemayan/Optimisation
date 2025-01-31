import random

def fonction(a,b,c,d,e,f,x,y):
	return a*x**2+b*y**2+c*x*y+d*x+e*y+f


a=float(input("choix de a : "))
b=float(input("choix de b : "))
c=float(input("choix de c : "))
d=float(input("choix de d : "))
e=float(input("choix de e : "))
f=float(input("choix de f : "))

xmin=float(input("choix de xmin: "))
xmax=float(input("choix de xmax: "))
while (xmin>xmax):
	print("bornes de x non conformes ! xmin<=xmax")
	xmin=float(input("choix de xmin: "))
	xmax=float(input("choix de xmax: "))

ymin=float(input("choix de ymin: "))
ymax=float(input("choix de ymax: "))
while (ymin>ymax):
	print("bornes de y non conformes ! ymin<=ymax");
	ymin=float(input("choix de ymin: "))
	ymax=float(input("choix de ymax: "))


print("Optimisation de la fonction f(x,y)=",a,"x^2+",b,"y^2+",c,"xy+",d,"x+",e,"y+",f)
n=int(input("nombre de répétitions (0<n<=100000) : ")) #maximum choisis arbitrairement
while(n<0 or n>100000):
	print("nombre de répétitions trop important !")
	n=int(input("nombre de répétitions (0<n<=100000) : "))

x_optimise = random.uniform(xmin, xmax)
y_optimise=random.uniform(ymin, ymax)
f_optimise=fonction(a,b,c,d,e,f,x_optimise,y_optimise)
if(n<=20):
	print("f(",x_optimise,",",y_optimise,")=",f_optimise)

for i in range(n-1):
	x2 = random.uniform(xmin, xmax)
	y2=random.uniform(ymin, ymax)
	f2 = fonction(a,b,c,d,e,f,x2,y2)
	if (f2<f_optimise):
		x_optimise=x2;
		y_optimise=y2;
		f_optimise=f2;
	if(n<=20):
		print("f(",x2,",",y2,")=",f2)
print("le couple pour lequel la fonction est la plus optimale est (",x_optimise,",",y_optimise,")")

