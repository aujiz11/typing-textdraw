// Typing-TextDraw by Aujiz
#if defined typing_textdraw_included
    #endinput
#endif
#define typing_textdraw_included

#if !defined TYPING_MAX_LENGTH
    #define TYPING_MAX_LENGTH 1028
#endif

#if !defined TYPING_INTERVAL
    #define TYPING_INTERVAL 100
#endif

static g_TypingText[MAX_PLAYERS][TYPING_MAX_LENGTH];
static g_TypingIndex[MAX_PLAYERS];
static PlayerText:g_TypingTextDraw[MAX_PLAYERS];
static g_TypingTimer[MAX_PLAYERS];

static ResetTypingTextDraw(playerid)
{
    g_TypingText[playerid][0] = '\0';
    g_TypingIndex[playerid] = 0;
    g_TypingTextDraw[playerid] = INVALID_PLAYER_TEXT_DRAW;
    g_TypingTimer[playerid] = INVALID_TIMER;
}

stock ShowTypingTextDraw(playerid, PlayerText:id, const text[], interval = TYPING_INTERVAL)
{
    if(IsValidTimer(g_TypingTimer[playerid])) {
        KillTimer(g_TypingTimer[playerid]);
        ResetTypingTextDraw(playerid);
    }

    format(g_TypingText[playerid], sizeof(g_TypingText[]), "%s", text);
    g_TypingIndex[playerid] = 0;
    g_TypingTextDraw[playerid] = id;
    PlayerTextDrawSetString(playerid, id, "_");
    PlayerTextDrawShow(playerid, id);
    g_TypingTimer[playerid] = SetTimerEx("TypingTextDrawTimer", interval, true, "i", playerid);
}

forward TypingTextDrawTimer(playerid);
public TypingTextDrawTimer(playerid)
{
    if(!IsPlayerConnected(playerid)) {
        KillTimer(g_TypingTimer[playerid]);
        g_TypingTimer[playerid] = INVALID_TIMER;
        return 1;
    }

    new idx = g_TypingIndex[playerid];
    new text[TYPING_MAX_LENGTH];
    format(text, sizeof(text), "%s", g_TypingText[playerid]);
    new len = strlen(text);
    if (idx < len)
    {
        new buffer[TYPING_MAX_LENGTH];
        strmid(buffer, text, 0, idx + 1, sizeof(buffer));
        PlayerTextDrawSetString(playerid, g_TypingTextDraw[playerid], buffer);
        g_TypingIndex[playerid]++;
    }
    else
    {
        KillTimer(g_TypingTimer[playerid]);
        g_TypingTimer[playerid] = INVALID_TIMER;
    }
    return 1;
}

public OnPlayerConnect(playerid)
{
    ResetTypingTextDraw(playerid);

    #if defined TTD_OnPlayerConnect
        return TTD_OnPlayerConnect(playerid);
    #else
        return 1;
    #endif
}

#if defined _ALS_OnPlayerConnect
	#undef OnPlayerConnect
#else
	#define _ALS_OnPlayerConnect
#endif

#define OnPlayerConnect TTD_OnPlayerConnect
#if defined TTD_OnPlayerConnect
	forward TTD_OnPlayerConnect(playerid);
#endif