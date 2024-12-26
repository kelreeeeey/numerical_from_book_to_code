from python_libs.problemset_a1 import ProblemA1

def problem_a() -> None:

    cmod = ProblemA1()
    setA_1 = cmod.constantSummation(6.0, 1.0)
    setA_2 = cmod.constantSummation(250.0, 1.0)
    setA_3 = cmod.linearSummation(15.0)
    setA_4 = cmod.linearSummation(10.0)
    setA_5 = cmod.bicubicSummation(5.0)
    setA_6 = cmod.quadraticSummation(7.0)

    N7, N8 = 100.0, 100.0
    setA_7_a = 2.0
    setA_7_b = cmod.linearSummation(N7)
    setA_7_c = cmod.constantSummation(3.0, N7)

    setA_8_a = cmod.quadraticSummation(N8)
    setA_8_b = 2 * cmod.linearSummation(N8)
    setA_8_c = N8

    setA_7 = (setA_7_a * setA_7_b) - setA_7_c
    setA_8 = setA_8_a - setA_8_b + setA_8_c

    print(f"Set A.1:  constant summation: {setA_1:10.2f}")
    print(f"Set A.2:  constant summation: {setA_2:10.2f}")
    print(f"Set A.3:    linear summation: {setA_3:10.2f}")
    print(f"Set A.4:    linear summation: {setA_4:10.2f}")
    print(f"Set A.5:   bicubic summation: {setA_5:10.2f}")
    print(f"Set A.6: quadratic summation: {setA_6:10.2f}")
    print(f"Set A.7:    linear summation: {setA_7:10.2f}")
    print(f"Set A.8: quadratic summation: {setA_8:10.2f}")

    return None

def main():
    problem_a()

if __name__ == "__main__":
    main()

