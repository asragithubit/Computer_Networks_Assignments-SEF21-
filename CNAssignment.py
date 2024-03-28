import matplotlib.pyplot as plt


def helper_NRZ(bits):
    amplitudes = []
    for bit in bits:
        if bit == '1':
            amplitudes.append(1)
        else:
            amplitudes.append(0)
    return amplitudes

def NRZ(bits):
    time = range(len(bits))
    amplitudes=helper_NRZ(bits)

        #Adjusts the width & length of Graph 
    plt.figure(figsize=(4, 2)) 

        #Labels denote the names to be displayed on x and y axis
    plt.xlabel("Time")
    plt.ylabel("Amplitude")

        #xticks & yticks represent the values that should be displayed on both the axis
    plt.xticks(time,[""]*len(bits))
    plt.yticks([0,1],["",""])

        #Lines on top & right side will be disappeared
    plt.gca().spines['top'].set_visible(False)
    plt.gca().spines['right'].set_visible(False)

        #Limits the values of y_axis
    plt.ylim(-0.5, 1.5) 
    plt.xlim(-0.5, len(bits) - 0.5)
 

    for i, bit in enumerate(bits):
        plt.text(i - 0.3, 1.1, bit, ha='center')

    plt.gca().spines['bottom'].set_position(('data', 0)) 

    plt.grid(axis="x",linestyle="--",color="black")
    plt.step(time, amplitudes, linestyle='-', color='black',label="NRZ_Line Coding Scheme")
    plt.legend(loc='upper center', bbox_to_anchor=(0.5, 1.15)) 
    plt.show()

def helper_NRZL(bits):
    amplitude=[]
    for bit in bits:
        if bit=='0':
            amplitude.append(1)
        else:
            amplitude.append(-1)
    return amplitude


def NRZ_L(bits):
    
    plt.figure(figsize=(5,2))
    plt.gca().spines['bottom'].set_position(('data', 0)) 
    for i, bit in enumerate(bits):
        plt.text(i - 0.3, 1.1, bit, ha='center')

    plt.gca().spines['top'].set_visible(False)
    plt.gca().spines['right'].set_visible(False)

    plt.xlabel("Time")
    plt.ylabel("Amplitude")

    plt.xticks(range(len(bits)),[""]*len(bits))
    plt.yticks([-1,0,1],["","",""])

    plt.ylim(-1.5,1.5)
    plt.xlim(-0.5, len(bits) - 0.5)

    time=range(len(bits))
    amplitude=helper_NRZL(bits)

    plt.grid(axis="x",linestyle="--",color="black")
    plt.step(time,amplitude,linestyle='-', color='black',label="NRZ_L Line Coding Scheme")
    plt.legend(loc='upper center', bbox_to_anchor=(0.5, 1.15)) 
    plt.show()


def helper_NRZI(bits):
    amplitude=[]
    prevAmplitude=1
    for bit in bits:
        if bit=='0':
            amplitude.append(prevAmplitude)     
        else:
            if(prevAmplitude==1):
                amplitude.append(-1)
                prevAmplitude=-1
            else:
                amplitude.append(1)
                prevAmplitude=1
    return amplitude

def NRZ_I(bits):
    plt.figure(figsize=(5,2))
    plt.gca().spines['bottom'].set_position(('data', 0)) 
    for i, bit in enumerate(bits):
        plt.text(i-0.3, 1.1, bit, ha='center')

    plt.gca().spines['top'].set_visible(False)
    plt.gca().spines['right'].set_visible(False)

    plt.xlabel("Time")
    plt.ylabel("Amplitude")

    plt.xticks(range(len(bits)),[""]*len(bits))
    plt.yticks([-1,0,1],["","",""])

    plt.ylim(-1.5,1.5)
    plt.xlim(-0.5, len(bits) - 0.5)

    time=range(len(bits))
    amplitude=helper_NRZI(bits)
    
    plt.grid(axis="x",linestyle="--",color="black")
    plt.step(time,amplitude,linestyle='-', color='black',label="NRZ_I Line Coding Scheme")
    plt.legend(loc='upper center', bbox_to_anchor=(0.5, 1.15)) 
    plt.show()

def helper_AMI(bits):

    amplitude=[]
    prevAmplitude=-1
    for bit in bits:
        if bit=='0':
            amplitude.append(0)     
        else:
            if(prevAmplitude==1):
                amplitude.append(-1)
                prevAmplitude=-1 
            else:
                amplitude.append(1)
                prevAmplitude=1
    return amplitude

def AMI(bits):
    plt.figure(figsize=(5,2))
    plt.gca().spines['bottom'].set_position(('data', 0)) 
    for i, bit in enumerate(bits):
        plt.text(i-0.3, 1.1, bit, ha='center')

    plt.gca().spines['top'].set_visible(False)
    plt.gca().spines['right'].set_visible(False)

    plt.xlabel("Time")
    plt.ylabel("Amplitude")

    plt.xticks(range(len(bits)),[""]*len(bits))
    plt.yticks([-1,0,1],["","",""])

    plt.ylim(-1.5,1.5)
    plt.xlim(-0.5, len(bits) - 0.5)

    time=range(len(bits))
    amplitude=helper_AMI(bits)
    
    plt.grid(axis="x",linestyle="--",color="black")
    plt.step(time,amplitude,linestyle='-', color='black',label="AMI Line Coding Scheme")
    plt.legend(loc='upper center', bbox_to_anchor=(0.5, 1.15)) 
    plt.show()


def helper_PseudoTernary(bits):
    amplitude=[]
    prevAmplitude=-1
    for bit in bits:
        if bit=='1':
            amplitude.append(0)     
        else:
            if(prevAmplitude==1):
                amplitude.append(-1)
                prevAmplitude=-1
            else:
                amplitude.append(1)
                prevAmplitude=1
    return amplitude

        

def PseudoTernary(bits):
    plt.figure(figsize=(5,2))
    plt.gca().spines['bottom'].set_position(('data', 0)) 
    for i, bit in enumerate(bits):
        plt.text(i-0.3, 1.1, bit, ha='center')

    plt.gca().spines['top'].set_visible(False)
    plt.gca().spines['right'].set_visible(False)

    plt.xlabel("Time")
    plt.ylabel("Amplitude")

    plt.xticks(range(len(bits)),[""]*len(bits))
    plt.yticks([-1,0,1],["","",""])
    plt.ylim(-1.5,1.5)
    plt.xlim(-0.5, len(bits) - 0.5)

    time=range(len(bits))
    amplitude=helper_PseudoTernary(bits)

    plt.grid(axis="x",linestyle="--",color="black")
    plt.step(time,amplitude,linestyle='-', color='black',label="PseudoTernary Line Coding Scheme")
    plt.legend(loc='upper center', bbox_to_anchor=(0.5, 1.15)) 
    plt.show()

def helper_Manchester(bits):
    
    amplitude=[]
    for bit in bits:
        if(bit=='0'):
            amplitude.append(1)
            amplitude.append(-1)
        else:
            amplitude.append(-1)
            amplitude.append(1)
    return amplitude

def Manchester(bits):
    
    plt.figure(figsize=(5,2))
    plt.xlabel("Time")
    plt.ylabel("Amplitude")
    plt.gca().spines["top"].set_visible(False)
    plt.gca().spines["right"].set_visible(False)
    plt.gca().spines["bottom"].set_position(("data",0))


    plt.xticks(range(0, 2 * len(bits), 2), bits)
    plt.yticks([-1,0,1],["","",""])
    plt.ylim(-1.5,1.5)

    amplitude=helper_Manchester(bits)
    time=range(len(bits)*2)

    
    plt.step(time,amplitude,where="post",linestyle="-",color="black",label="Manchester_Line Coding Scheme")
    plt.legend(loc='upper center', bbox_to_anchor=(0.5, 1.15)) 
    plt.grid(axis="x",color="black",linestyle=":")
    plt.show()    
    
def helper_DiffManchester(bits):
    prevBit=1
    amplitude=[]

    for bit in bits:
        if bit=='0':
            if prevBit==-1:
                amplitude.append(1)
                amplitude.append(-1)
                prevBit=-1
            else:
                amplitude.append(-1)
                amplitude.append(1)
                prevBit=1
        else:
            if prevBit==-1:
                amplitude.append(-1)
                amplitude.append(1)
                prevBit=1
            else:
                amplitude.append(1)
                amplitude.append(-1)
                prevBit=-1

    return amplitude

def Diffrential_Manchester(bits):

    plt.figure(figsize=(5,2))
    plt.xlabel("Time")
    plt.ylabel("Amplitude")
    plt.gca().spines["top"].set_visible(False)
    plt.gca().spines["right"].set_visible(False)
    plt.gca().spines["bottom"].set_position(("data",0))

    plt.xticks(range(0, 2 * len(bits), 2), bits)
    plt.yticks([-1,0,1],["","",""])
    plt.ylim(-1.5,1.5)

    amplitude=helper_DiffManchester(bits)
    time=range(len(bits)*2)
            
    plt.step(time,amplitude,where="post",linestyle="-",color="black",label="Diffrential Manchester_Line Coding Scheme")
    plt.legend(loc='upper center', bbox_to_anchor=(0.5, 1.15))
    plt.grid(axis="x",color="black",linestyle=":") 
    plt.show()    
    

def helper_RZ(bits):
    
    amplitude=[]
    for bit in bits:
        if bit=='0':
            amplitude.append(-1)
            amplitude.append(0)
        else:
            amplitude.append(1)
            amplitude.append(0)
    return amplitude


def RZ(bits):

    plt.figure(figsize=(5,2))
    plt.xlabel("Time")
    plt.ylabel("Amplitude")
    plt.gca().spines["top"].set_visible(False)
    plt.gca().spines["right"].set_visible(False)
    plt.gca().spines["bottom"].set_position(("data",0))

    plt.xticks(range(0, 2 * len(bits), 2), bits)
    plt.yticks([-1,0,1],["","",""])
    plt.ylim(-1.5,1.5)

    amplitude=helper_RZ(bits)
    time=range(len(bits)*2)
            
    plt.step(time,amplitude,linestyle="-",color="black",label="RZ_Line Coding Scheme")
    plt.legend(loc='upper center', bbox_to_anchor=(0.5, 1.15)) 
    plt.grid(axis="x",color="black",linestyle=":")
    plt.show()    

     
def _2B1Q(bits):
    plt.figure(figsize=(5, 2))
    plt.xlabel("Time")
    plt.ylabel("Amplitude")
    plt.gca().spines["top"].set_visible(False)
    plt.gca().spines["right"].set_visible(False)
    plt.gca().spines["bottom"].set_position(("data", 0))

    encoding = {
        "00": -3,
        "01": -1,
        "10": 1,
        "11": 3
    }

    if not all(bit in ['0', '1'] for bit in bits):
        print("Invalid input. The input should contain only '0' and '1' characters.")
        return

    if len(bits) % 2 != 0:
        bits += '0'

    pairs = [bits[i:i+2] for i in range(0, len(bits), 2)]
    signal = [encoding[pair] for pair in pairs]
    x_ticks = [f"{pair[0]}{pair[1]}" for pair in pairs]
    plt.yticks([-3, -1, 1, 3], ["", "", "", ""])
    plt.ylim(-3.5, 3.5)
    plt.step(range(len(signal)), signal, where='post', linestyle="-", color="black", drawstyle='steps-post',
             label="2B1Q_Line Coding Scheme")
    plt.legend(loc='upper center', bbox_to_anchor=(0.5, 1.15))
    plt.xticks(range(len(x_ticks)), x_ticks)

    plt.grid(axis="x", color="black", linestyle=":")
    plt.show()


def main():
    
    print("\n\t\t--------------------------------Digital_To_Digital Conversion-----------------------")
    print("\t\t\t\t\t\t----------------------------")


    while(True):
        print("\n=======================================================================\n")
        print(" 1. NRZ_Line Coding Scheme")
        print(" 2. NRZ_L Line Coding Scheme")
        print(" 3. NRZ_I Line Coding Scheme")
        print(" 4. AMI_Line Coding Scheme")
        print(" 5. PseudoTernary_Line Coding Scheme")
        print(" 6. RZ_Line Coding Scheme")
        print(" 7. Manchester_Line Coding Scheme")
        print(" 8. Diffrential_Manchester Line Coding Scheme")
        print(" 9. 2B1Q_Line Coding Scheme")
        print("-1: To Quit")
        print("\n=======================================================================\n")
        choice=int(input("Your Choice Here: "))

        if(choice==-1):
            break
        elif(choice==1):
            
            while(True):
                flag=True
                bits=input("Stream Of Bits: ")
                for bit in bits:
                    if bit!='0' and bit!='1':
                        print("Invalid Bit Stream!!!")
                        print("Try Again!!!")
                        flag=False
                        break
                if flag==True:
                    break
  
            NRZ(bits)

        elif(choice==2):
            while(True):
                flag=True
                bits=input("Stream Of Bits: ")
                for bit in bits:
                    if bit!='0' and bit!='1':
                        print("Invalid Bit Stream!!!")
                        print("Try Again!!!")
                        flag=False
                        break
                if flag==True:
                    break
  
            NRZ_L(bits)

        elif(choice==3):
            while(True):
                flag=True
                bits=input("Stream Of Bits: ")
                for bit in bits:
                    if bit!='0' and bit!='1':
                        print("Invalid Bit Stream!!!")
                        print("Try Again!!!")
                        flag=False
                        break
                if flag==True:
                    break
  
            NRZ_I(bits)
        
        elif(choice==4):
            while(True):
                flag=True
                bits=input("Stream Of Bits: ")
                for bit in bits:
                    if bit!='0' and bit!='1':
                        print("Invalid Bit Stream!!!")
                        print("Try Again!!!")
                        flag=False
                        break
                if flag==True:
                    break
  
            AMI(bits)
            
        elif(choice==5):
            while(True):
                flag=True
                bits=input("Stream Of Bits: ")
                for bit in bits:
                    if bit!='0' and bit!='1':
                        print("Invalid Bit Stream!!!")
                        print("Try Again!!!")
                        flag=False
                        break
                if flag==True:
                    break
  
            PseudoTernary(bits)
            
        elif(choice==6):
            while(True):
                flag=True
                bits=input("Stream Of Bits: ")
                for bit in bits:
                    if bit!='0' and bit!='1':
                        print("Invalid Bit Stream!!!")
                        print("Try Again!!!")
                        flag=False
                        break
                if flag==True:
                    break
  
            RZ(bits)
        
        elif(choice==7):
            while(True):
                flag=True
                bits=input("Stream Of Bits: ")
                for bit in bits:
                    if bit!='0' and bit!='1':
                        print("Invalid Bit Stream!!!")
                        print("Try Again!!!")
                        flag=False
                        break
                    
                if flag==True:
                    break
            Manchester(bits)
        
        elif(choice==8):
            while(True):
                flag=True
                bits=input("Stream Of Bits: ")
                for bit in bits:
                    if bit!='0' and bit!='1':
                        print("Invalid Bit Stream!!!")
                        print("Try Again!!!")
                        flag=False
                        break
                if flag==True:
                    break
              
            Diffrential_Manchester(bits)
        
        elif(choice==9):
            while(True):
                flag=True
                bits=input("Stream Of Bits: ")
                for bit in bits:
                    if bit!='0' and bit!='1':
                        print("Invalid Bit Stream!!!")
                        print("Try Again!!!")
                        flag=False
                        break
                if flag==True:
                    break
              
            _2B1Q(bits)
        else:
            print("Invalid Choice")
            break
            
                        
                    
if __name__ == "__main__":
    main()