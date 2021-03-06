#pragma once
#include "UIObject.h"

class IUIButtonOnMouseListner;

class UIButton : public UIObject
{
private:
	enum State
	{
        kIdle,
        kMouseOver,
        kSelect,
	};
    static const int m_kNumState = 3;

    IUIButtonOnMouseListner*   m_pIUIButtonOnMouseListner;
    State                      m_state;
    int                        m_KeyToRespond;
    bool                       m_bPrevIsMouseOn;
    bool                       m_bCurrIsMouseOn;
    vector<LPDIRECT3DTEXTURE9> m_vecTexture;

    void UpdateOnMouseEnterExit();
    void UpdateOnMouseDownUpDrag();

public:
	UIButton();
	virtual ~UIButton();

	virtual void Update() override;
	virtual void Render() override;

    void UpdateOnMouse();

	void SetTexture(const string& idle, const string& mouseOver, const string& select);
	void SetText(const LPD3DXFONT font, const LPCTSTR text);
    void SetKeyToRespond(const int key);
    void SetIUIButtonOnMouseListner(IUIButtonOnMouseListner& val);
};

class IUIButtonOnMouseListner
{
private:
    UIButton* m_pUIButton;

public:
    IUIButtonOnMouseListner();
    virtual ~IUIButtonOnMouseListner() = default;

    virtual void OnMouseEnter() = 0;
    virtual void OnMouseExit() = 0;
    virtual void OnMouseDown(const int key) = 0;
    virtual void OnMouseUp(const int key) = 0;
    virtual void OnMouseDrag(const int key) = 0;

    void SetUIButton(UIButton& val);
    UIButton* GetUIButton() const;
};
