#pragma once
#include<vector>

class Nation;

class InfoData {
public:
	InfoData();
	~InfoData();
	InfoData(const InfoData& src);
	InfoData& operator=(const InfoData& rsh);


	const std::vector<Nation*>& getNations() const;
	const std::vector<int>& getHps() const;
	const std::vector<int>& getWps() const;
	const std::vector<int>& getMds() const;
	const std::vector<int>& getFds() const;

	std::vector<Nation*>& getNations() ;
	std::vector<int>& getHps() ;
	std::vector<int>& getWps() ;
	std::vector<int>& getMds() ;
	std::vector<int>& getFds();

	void updateData();
private:
	std::vector<Nation*> m_Nations;
	std::vector<int> m_Hps;
	std::vector<int> m_Wps;
	std::vector<int> m_Mds;
	std::vector<int> m_Fds;
};