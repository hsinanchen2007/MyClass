
#define CEL_MAX_VALUE  55.0f
#define CEL_MIN_VALUE  5.0f

#define CEL_TO_FAH(t)  ((t) *  9.0f / 5.0f + 32)
void SetTemCof(float temCof);
float GetCelTem(void);
float GetFahTem(void);

