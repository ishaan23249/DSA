memory={
    "0x00010000":0,
    "0x00010004":0,
    "0x00010008":0,
    "0x0001000c":0,
    "0x00010010":0,
    "0x00010014":0,
    "0x00010018":0,
    "0x0001001c":0,
    "0x00010020":0,
    "0x00010024":0,
    "0x00010028":0,
    "0x0001002c":0,
    "0x00010030":0,
    "0x00010034":0,
    "0x00010038":0,
    "0x0001003c":0,
    "0x00010040":0,
    "0x00010044":0,
    "0x00010048":0,
    "0x0001004c":0,
    "0x00010050":0,
    "0x00010054":0,
    "0x00010058":0,
    "0x0001005c":0,
    "0x00010060":0,
    "0x00010064":0,
    "0x00010068":0,
    "0x0001006c":0,
    "0x00010070":0,
    "0x00010074":0,
    "0x00010078":0,
    "0x0001007c":0,
}
register_track={
  "zero":0,
  "ra":0,
  "sp":0,
  "gp":0,
  "tp":0,
  "t0":0,
  "t1":0,
  "t2":0,
  "s0":0,
  "fp":0,
  "s1":0,
  "a0":0,
  "a1":0,
  "a2":0,
  "a3":0,
  "a4":0,
  "a5":0,
  "a6":0,
  "a7":0,
  "s2":0,
  "s3":0,
  "s4":0,
  "s5":0,
  "s6":0,
  "s7":0,
  "s8":0,
  "s9":0,
  "s10":0,
  "s11":0,
  "t3":0,
  "t4":0,
  "t5":0,
  "t6":0,
}

registor={
    "00000":"zero",
    "00001":"ra",
    "00010":"sp",
    "00011":"gp",
    "00100":"tp",
    "00101":"t0",
    "00110":"t1",
    "00111":"t2",
    "01000":"s0",
    "01000":"fp",
    "01001":"s1",
    "01010":"a0",
    "01011":"a1",
    "01100":"a2",
    "01101":"a3",
    "01110":"a4",
    "01111":"a5",
    "10000":"a6",
    "10001":"a7",
    "10010":"s2",
    "10011":"s3",
    "10100":"s4",
    "10101":"s5",
    "10110":"s6",
    "10111":"s7",
    "11000":"s8",
    "11001":"s9",
    "11010":"s10",
    "11011":"s11",
    "11100":"t3",
    "11101":"t4",
    "11110":"t5",
    "11111":"t6",
}
def findTwoscomplement(str):

    n = len(str)
    i = n - 1

    while(i >= 0):

        if (str[i] == '1'):

            break
 

        i -= 1

    if (i == -1):

        return '1'+str
 

    k = i - 1

    while(k >= 0):



        if (str[k] == '1'):

            str = list(str)

            str[k] = '0'

            str = ''.join(str)

        else:

            str = list(str)

            str[k] = '1'

            str = ''.join(str)
 

        k -= 1

    return str
def btod(val):
   if(val[0]==0):
      return int(val,2)
   else:
      val_final=findTwoscomplement(val)
      return -1*int(val_final,2)
from bitstring import BitArray
def unsigned(bString):
    value = BitArray(bin=bString).int
    return value
def simulator(line,PC):
    opcode=line[25:]
    func3=line[17:20]
    rd=line[20:25]
    rs1=line[12:17]
    rs2=line[7:12]
    func7=line[0:7]
    if(opcode=='0000011'):
      imm1=line[0:12]
      final_imm=imm1[0]*20+imm1
      register_track[registor[rd]]=memory[hex(register_track[registor[rs1]]+btod(final_imm))]
      PC=PC+4
    if(opcode=='0010011'):
        if func3=='000':
            imm1=line[0:12]
            final_imm=imm1[0]*20+imm1
            register_track[registor[rd]]=register_track[registor[rs1]]+btod(final_imm)
            PC=PC+4
        if func3=='011':
            imm1=line[0:12]
            final_imm=imm1[0]*20+imm1
            if unsigned(rs1)<unsigned(final_imm):
               register_track[registor[rd]]=1
            PC=PC+4    
    if(opcode=='1100111'):
        imm1=line[0:12]
        final_imm=imm1[0]*20+imm1
        register_track[registor[rd]]=PC+4
        pc=register_track['t1']+btod(final_imm)
        if(pc%2!=0):
           pc=pc-1
        PC=pc

    if(opcode=='0100011'):
       imm1=func7+rd
       final_imm=imm1[0]*20+imm1
       memory[hex(register_track[registor[rs1]]+btod(final_imm))]=register_track[registor[rs2]]
       PC=PC+4

    if(opcode=='0110111'):
       final_imm=line[0:21]
       register_track[registor[rd]]=btod((final_imm+"000000000000"))
       PC=PC+4
    if(opcode=='0010111'):
        final_imm=line[0:21]
        register_track[registor[rd]]=PC+btod((final_imm+"000000000000"))         
        PC=PC+4
    if(opcode=='1100011'):
      #beq instruction:
      imm1=line[0:7]
      imm2=line[20:25]
      final_imm=imm1[0]*20+imm2[-1]+imm1[1:]+imm2[0:-1]
      if(func3=='000'):
        if(register_track[registor[rs1]]==register_track[registor[rs2]]):
          PC=PC+final_imm
          
        else:
          PC=PC+4
      #bne
      if(func3=='001'):
        if(register_track[registor[rs1]]!=register_track[registor[rs2]]):
          PC=PC+final_imm
        else:
          PC=PC+4
      #blt
      if(func3=='100'):
        if(register_track[registor[rs1]]<register_track[registor[rs2]]):
          PC=PC+final_imm
        else:
          PC=PC+4
    #   #bge
    #   if(func3=='101'):
        
    #   #bltu
    #   if(func3=='110'):
    #   #bgeu
    #   if(func3=='111'):