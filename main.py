import time
import random


def ler_temperatura():
    temperatura = random.uniform(20.0, 35.0)  
    return temperatura

def ler_umidade_ar():
    umidade_ar = random.uniform(40.0, 80.0)
    return umidade_ar

def ler_umidade_solo():
    return random.uniform(10.0, 100.0)

def controlar_irrigacao(umidade_solo, limite_umidade=40.0):
    if umidade_solo < limite_umidade:
        print("💧 Umidade baixa! Ativando irrigação...")
        irrigando = True
    else:
        print("✅ Umidade adequada. Irrigação desligada.")
        irrigando = False
    return irrigando

# Loop principal
def sistema_horta():
    while True:
        print("📡 Monitorando a horta...")
        
        temperatura = ler_temperatura()
        umidade_ar = ler_umidade_ar()
        umidade_solo = ler_umidade_solo()

        print(f"🌡️ Temperatura do ar: {temperatura:.1f}°C")
        print(f"💨 Umidade do ar: {umidade_ar:.1f}%")
        print(f"🌱 Umidade do solo: {umidade_solo:.1f}%")

        controlar_irrigacao(umidade_solo)

        print("-" * 40)
        time.sleep(5)

sistema_horta()