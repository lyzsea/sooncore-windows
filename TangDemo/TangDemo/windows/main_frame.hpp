#ifndef MAINFRAME_HPP
#define MAINFRAME_HPP

//#include "skin_change_event.hpp"
#include "participants_list.hpp"
#include "WindowWithShadow.hpp"

class MainFrame : public CWindowWithShadow//public WindowImplBase
{
public:

	MainFrame();
	~MainFrame();

public:
	LPCTSTR GetWindowClassName() const;	
	virtual void OnFinalMessage(HWND hWnd);
	virtual void InitWindow();
	virtual LRESULT ResponseDefaultKeyEvent(WPARAM wParam);
	virtual CDuiString GetSkinFile();
	virtual CDuiString GetSkinFolder();
	virtual UILIB_RESOURCETYPE GetResourceType() const;
	virtual CControlUI* CreateControl(LPCTSTR pstrClass);
	virtual LRESULT OnSysCommand(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	//virtual LRESULT HandleCustomMessage(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	virtual LRESULT OnClose(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	virtual LPCTSTR GetResourceID() const;

	LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam) override;

    //DWORD GetBkColor();
    //void SetBkColor(DWORD dwBackColor);

protected:	

	void Notify(TNotifyUI& msg);
	void OnPrepare(TNotifyUI& msg);
	void OnExit(TNotifyUI& msg);
	void OnTimer(TNotifyUI& msg);

private:

	void UpdateFriendsList();
private:
	int bk_image_index_;

	PtiptListItemInfo myself_info_;
	Node *root_parent_;
	std::vector<PtiptListItemInfo> friends_;

	//SkinChangedObserver skin_changed_observer_;
};

#endif // MAINFRAME_HPP