#if defined _INC_char_callbacks_inc
    #endinput
#endif
#define _INC_char_callbacks_inc

forward OnCharacterCreated(const character);
public OnCharacterCreated(const character)
{
    char_UniqueID[character] = cache_insert_id();
    return 1;
}