import math
a1 = float(input("Enter the value of a1 "))
a2 = float(input("Enter the value of a2 "))
a3 = float(input("Enter the value of a3 "))
x3 = float(input("Enter x co-ordinate of end-effector"))
y3 = float(input("Enter y co-ordinate of end-effector"))
par_sum = float(input("Enter partial angles sum. "))
# We have to find three angles theta1, theta2, theta3.
x2 = x3 - a3*(math.cos(par_sum))
y2 = y3 - a3*(math.sin(par_sum))


cosphi2 = ((x2**2) + (y2**2) - (a1**2) - (a1**2))/(2*a1*a2)
phi2 = math.acos(cosphi2)


# phi1, phi2, phi3 are explained in derivation. 
s1 = (a1 + a2*math.cos(phi2))*y2 - (x2*a2)*math.sin(phi2)
c1 = (a1 + a2*math.cos(phi2))*x2 - (y2*a2)*math.sin(phi2)

tanphi1 = s1/c1
phi1 = math.atan(tanphi1)
phi3 = par_sum - phi1 - phi2

# Finding theta1, theta2, theta3. 
theta1 = phi1 
theta2 = phi2 + theta1
theta3 = theta2 + phi3

print("Value of theta1 is ", theta1)
print("Value of theta2 is ", theta2)
print("Value of theta3 is ", theta3)
