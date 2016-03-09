/*
 * EAP peer method: EAP-ABA 
 * 2016 Bachelorthesis Abdullah Rasool
 * Radboud University Nijmegen
 * See README for more details.
 */

#include "includes.h"

#include "common.h"
#include "eap_i.h"


static void * eap_aba_init(struct eap_sm *sm)
{
	/* No need for private data. However, must return non-NULL to indicate
	 * success. */
	//return 1;
	return (void *) 1;
}


static void eap_aba_deinit(struct eap_sm *sm, void *priv)
{
}


static struct wpabuf * eap_aba_process(struct eap_sm *sm, void *priv,
				       struct eap_method_ret *ret,
				       const struct wpabuf *reqData)
{
	struct wpabuf *resp;
	//const u8 *pos, *challenge, *password;
	//u8 *rpos, id;
	//size_t len, challenge_len, password_len;

	wpa_printf(MSG_INFO, "Hello, its me !!");

	
	return resp;
}


int eap_peer_aba_register(void)
{
	struct eap_method *eap;
	int ret;

	eap = eap_peer_method_alloc(EAP_PEER_METHOD_INTERFACE_VERSION,
				    EAP_VENDOR_IETF, EAP_TYPE_ABA, "ABA");
	if (eap == NULL)
		return -1;
	else
		wpa_printf(MSG_INFO, "Everything went wrogn");

	eap->init = eap_aba_init;
	eap->deinit = eap_aba_deinit;
	eap->process = eap_aba_process;

	ret = eap_peer_method_register(eap);
	if (ret)
		eap_peer_method_free(eap);
	return ret;
}
