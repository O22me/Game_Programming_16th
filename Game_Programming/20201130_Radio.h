#pragma once

class Speaker
{
	bool m_bPower;
	float m_fVolume;
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
//
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