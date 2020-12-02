#pragma once

class Speaker
{
	bool m_bPower; //전원 On/Off
	float m_fVolume; //볼륨 Up/Down
public:
	Speaker()
	{
		m_bPower = false;
		m_fVolume = 0;
	}
	void SwitchOn()
	{
		m_bPower = true;
	}
	void SwitchOff()
	{
		m_bPower = false;
	}
	void VolumeUp()
	{
		m_fVolume++;
	}
	void VolumeDown()
	{
		m_fVolume--;
	}
};
class Antena
{
	float m_fHz;
public:
	void HzUp()
	{
		m_fHz++;
	}
	void HzDown()
	{
		m_fHz--;
	}
};
//라디오
//Is-a : 상속을 이용하면코드를 거의 작성하지 않고 만들 수 있다.
class RadioIs_a : public Speaker, public Antena
{
	//Is-a 방식

};
//has-a : 각 객체를 감싸는 함수를 만들어야 한다.
//만들 때 내부의 부품을 더 좋은 부품으로 사용할 수 있다.
//(현실에 라디오라면 직접 인터페이스를 내부에 보드에 연결하므로 여기에 해당될 수도 있다.)
class RadioHas_a
{
	//has-a 방식
	Speaker* m_cSpeaker;
	Antena* m_cAntena;
public:
	RadioHas_a(Speaker* speaker, Antena* antena)
	{
		m_cSpeaker = speaker;
		m_cAntena = antena;
	}
	void SwitchOn()
	{
		m_cSpeaker->SwitchOn();
	}
	void SwitchOff()
	{
		m_cSpeaker->SwitchOff();
	}
	void VolumeUp()
	{
		m_cSpeaker->VolumeUp();
	}
	void VolumeDown()
	{
		m_cSpeaker->VolumeDown();
	}
	void HzUp()
	{
		m_cAntena->HzUp();
	}
	void HzDown()
	{
		m_cAntena->HzDown();
	}
};

void RadioMain()
{
	Speaker* p_spk = new Speaker;
	Antena* p_atn = new Antena;
	RadioHas_a cRadio(p_spk, p_atn);



	delete p_spk;
	delete p_atn;

	return;
}