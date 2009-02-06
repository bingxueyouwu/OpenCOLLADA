/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_STROKE_H__
#define __MayaDM_STROKE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPfxGeometry.h"
namespace MayaDM
{
class Stroke : public PfxGeometry
{
public:
	struct PathCurve{
		int samples;
		bool opposite;
		void write(FILE* file) const
		{
			fprintf(file,"%i ", samples);
			fprintf(file,"%i", opposite);
		}
	};
	struct PressureScale{
		float pressureScale_Position;
		float pressureScale_FloatValue;
		unsigned int pressureScale_Interp;
		void write(FILE* file) const
		{
			fprintf(file,"%f ", pressureScale_Position);
			fprintf(file,"%f ", pressureScale_FloatValue);
			fprintf(file,"%i", pressureScale_Interp);
		}
	};
public:
	Stroke(FILE* file,const std::string& name,const std::string& parent=""):PfxGeometry(file, name, parent, "stroke"){}
	virtual ~Stroke(){}
	void setSampleDensity(double sdn)
	{
		if(sdn == 1.0) return;
		fprintf(mFile,"setAttr \".sdn\" %f;\n", sdn);

	}
	void setSmoothing(double smo)
	{
		if(smo == 0.0) return;
		fprintf(mFile,"setAttr \".smo\" %f;\n", smo);

	}
	void setPerspective(bool per)
	{
		if(per == 1) return;
		fprintf(mFile,"setAttr \".per\" %i;\n", per);

	}
	void setUseNormal(bool usn)
	{
		if(usn == 0) return;
		fprintf(mFile,"setAttr \".usn\" %i;\n", usn);

	}
	void setNormal(const double3& nml)
	{
		fprintf(mFile,"setAttr \".nml\" -type \"double3\" ");
		nml.write(mFile);
		fprintf(mFile,";\n");

	}
	void setNormalX(double nmx)
	{
		if(nmx == 0.0) return;
		fprintf(mFile,"setAttr \".nml.nmx\" %f;\n", nmx);

	}
	void setNormalY(double nmy)
	{
		if(nmy == 0.0) return;
		fprintf(mFile,"setAttr \".nml.nmy\" %f;\n", nmy);

	}
	void setNormalZ(double nmz)
	{
		if(nmz == 1.0) return;
		fprintf(mFile,"setAttr \".nml.nmz\" %f;\n", nmz);

	}
	void setMinClip(double mnc)
	{
		if(mnc == 0.0) return;
		fprintf(mFile,"setAttr \".mnc\" %f;\n", mnc);

	}
	void setMaxClip(double mxc)
	{
		if(mxc == 1.0) return;
		fprintf(mFile,"setAttr \".mxc\" %f;\n", mxc);

	}
	void setPathCurve(size_t pcv_i,const PathCurve& pcv)
	{
		fprintf(mFile,"setAttr \".pcv[%i]\" ",pcv_i);
		pcv.write(mFile);
		fprintf(mFile,";\n");

	}
	void setSamples(size_t pcv_i,int smp)
	{
		if(smp == 0) return;
		fprintf(mFile,"setAttr \".pcv[%i].smp\" %i;\n", pcv_i,smp);

	}
	void setOpposite(size_t pcv_i,bool opp)
	{
		if(opp == false) return;
		fprintf(mFile,"setAttr \".pcv[%i].opp\" %i;\n", pcv_i,opp);

	}
	void setOutPoint(size_t opt_i,const double3& opt)
	{
		fprintf(mFile,"setAttr \".opt[%i]\" -type \"double3\" ",opt_i);
		opt.write(mFile);
		fprintf(mFile,";\n");

	}
	void setOutPoint(size_t opt_start,size_t opt_end,double* opt)
	{
		fprintf(mFile,"setAttr \".opt[%i:%i]\" ", opt_start,opt_end);
		size_t size = (opt_end-opt_start)*3+3;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",opt[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");

	}
	void startOutPoint(size_t opt_start,size_t opt_end)
	{
		fprintf(mFile,"setAttr \".opt[%i:%i]\"",opt_start,opt_end);

	}
	void appendOutPoint(double opt)
	{
		fprintf(mFile," %f",opt);

	}
	void endOutPoint()
	{
		fprintf(mFile,";\n");

	}
	void setOutPointX(size_t opt_i,double ox)
	{
		if(ox == 0.0) return;
		fprintf(mFile,"setAttr \".opt[%i].ox\" %f;\n", opt_i,ox);

	}
	void setOutPointY(size_t opt_i,double oy)
	{
		if(oy == 0.0) return;
		fprintf(mFile,"setAttr \".opt[%i].oy\" %f;\n", opt_i,oy);

	}
	void setOutPointZ(size_t opt_i,double oz)
	{
		if(oz == 0.0) return;
		fprintf(mFile,"setAttr \".opt[%i].oz\" %f;\n", opt_i,oz);

	}
	void setPressureMap1(unsigned int spm1)
	{
		if(spm1 == 0) return;
		fprintf(mFile,"setAttr \".spm1\" %i;\n", spm1);

	}
	void setPressureMin1(double ps1)
	{
		if(ps1 == 0.0) return;
		fprintf(mFile,"setAttr \".ps1\" %f;\n", ps1);

	}
	void setPressureMax1(double px1)
	{
		if(px1 == 1.0) return;
		fprintf(mFile,"setAttr \".px1\" %f;\n", px1);

	}
	void setPressureMap2(unsigned int spm2)
	{
		if(spm2 == 0) return;
		fprintf(mFile,"setAttr \".spm2\" %i;\n", spm2);

	}
	void setPressureMin2(double ps2)
	{
		if(ps2 == 0.0) return;
		fprintf(mFile,"setAttr \".ps2\" %f;\n", ps2);

	}
	void setPressureMax2(double px2)
	{
		if(px2 == 1.0) return;
		fprintf(mFile,"setAttr \".px2\" %f;\n", px2);

	}
	void setPressureMap3(unsigned int spm3)
	{
		if(spm3 == 0) return;
		fprintf(mFile,"setAttr \".spm3\" %i;\n", spm3);

	}
	void setPressureMin3(double ps3)
	{
		if(ps3 == 0.0) return;
		fprintf(mFile,"setAttr \".ps3\" %f;\n", ps3);

	}
	void setPressureMax3(double px3)
	{
		if(px3 == 1.0) return;
		fprintf(mFile,"setAttr \".px3\" %f;\n", px3);

	}
	void setPressureScale(size_t psc_i,const PressureScale& psc)
	{
		fprintf(mFile,"setAttr \".psc[%i]\" ",psc_i);
		psc.write(mFile);
		fprintf(mFile,";\n");

	}
	void setPressureScale_Position(size_t psc_i,float pscp)
	{
		if(pscp == 0.0) return;
		fprintf(mFile,"setAttr \".psc[%i].pscp\" %f;\n", psc_i,pscp);

	}
	void setPressureScale_FloatValue(size_t psc_i,float pscfv)
	{
		if(pscfv == 0.0) return;
		fprintf(mFile,"setAttr \".psc[%i].pscfv\" %f;\n", psc_i,pscfv);

	}
	void setPressureScale_Interp(size_t psc_i,unsigned int psci)
	{
		if(psci == 0) return;
		fprintf(mFile,"setAttr \".psc[%i].psci\" %i;\n", psc_i,psci);

	}
	void setPressure(size_t psr_i,double psr)
	{
		if(psr == 0.0) return;
		fprintf(mFile,"setAttr \".psr[%i]\" %f;\n", psr_i,psr);

	}
	void setPressure(size_t psr_start,size_t psr_end,double* psr)
	{
		fprintf(mFile,"setAttr \".psr[%i:%i]\" ", psr_start,psr_end);
		size_t size = (psr_end-psr_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",psr[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");

	}
	void startPressure(size_t psr_start,size_t psr_end)
	{
		fprintf(mFile,"setAttr \".psr[%i:%i]\"",psr_start,psr_end);

	}
	void appendPressure(double psr)
	{
		fprintf(mFile," %f",psr);

	}
	void endPressure()
	{
		fprintf(mFile,";\n");

	}
	void getSampleDensity()
	{
		fprintf(mFile,"\"%s.sdn\"",mName.c_str());

	}
	void getSmoothing()
	{
		fprintf(mFile,"\"%s.smo\"",mName.c_str());

	}
	void getPerspective()
	{
		fprintf(mFile,"\"%s.per\"",mName.c_str());

	}
	void getUseNormal()
	{
		fprintf(mFile,"\"%s.usn\"",mName.c_str());

	}
	void getNormal()
	{
		fprintf(mFile,"\"%s.nml\"",mName.c_str());

	}
	void getNormalX()
	{
		fprintf(mFile,"\"%s.nml.nmx\"",mName.c_str());

	}
	void getNormalY()
	{
		fprintf(mFile,"\"%s.nml.nmy\"",mName.c_str());

	}
	void getNormalZ()
	{
		fprintf(mFile,"\"%s.nml.nmz\"",mName.c_str());

	}
	void getMinClip()
	{
		fprintf(mFile,"\"%s.mnc\"",mName.c_str());

	}
	void getMaxClip()
	{
		fprintf(mFile,"\"%s.mxc\"",mName.c_str());

	}
	void getPathCurve(size_t pcv_i)
	{
		fprintf(mFile,"\"%s.pcv[%i]\"",mName.c_str(),pcv_i);

	}
	void getCurve(size_t pcv_i)
	{
		fprintf(mFile,"\"%s.pcv[%i].crv\"",mName.c_str(),pcv_i);

	}
	void getSamples(size_t pcv_i)
	{
		fprintf(mFile,"\"%s.pcv[%i].smp\"",mName.c_str(),pcv_i);

	}
	void getOpposite(size_t pcv_i)
	{
		fprintf(mFile,"\"%s.pcv[%i].opp\"",mName.c_str(),pcv_i);

	}
	void getOutPoint(size_t opt_i)
	{
		fprintf(mFile,"\"%s.opt[%i]\"",mName.c_str(),opt_i);

	}
	void getOutPointX(size_t opt_i)
	{
		fprintf(mFile,"\"%s.opt[%i].ox\"",mName.c_str(),opt_i);

	}
	void getOutPointY(size_t opt_i)
	{
		fprintf(mFile,"\"%s.opt[%i].oy\"",mName.c_str(),opt_i);

	}
	void getOutPointZ(size_t opt_i)
	{
		fprintf(mFile,"\"%s.opt[%i].oz\"",mName.c_str(),opt_i);

	}
	void getOutNormal(size_t onm_i)
	{
		fprintf(mFile,"\"%s.onm[%i]\"",mName.c_str(),onm_i);

	}
	void getOutNormalX(size_t onm_i)
	{
		fprintf(mFile,"\"%s.onm[%i].onx\"",mName.c_str(),onm_i);

	}
	void getOutNormalY(size_t onm_i)
	{
		fprintf(mFile,"\"%s.onm[%i].ony\"",mName.c_str(),onm_i);

	}
	void getOutNormalZ(size_t onm_i)
	{
		fprintf(mFile,"\"%s.onm[%i].onz\"",mName.c_str(),onm_i);

	}
	void getPressureMap1()
	{
		fprintf(mFile,"\"%s.spm1\"",mName.c_str());

	}
	void getPressureMin1()
	{
		fprintf(mFile,"\"%s.ps1\"",mName.c_str());

	}
	void getPressureMax1()
	{
		fprintf(mFile,"\"%s.px1\"",mName.c_str());

	}
	void getPressureMap2()
	{
		fprintf(mFile,"\"%s.spm2\"",mName.c_str());

	}
	void getPressureMin2()
	{
		fprintf(mFile,"\"%s.ps2\"",mName.c_str());

	}
	void getPressureMax2()
	{
		fprintf(mFile,"\"%s.px2\"",mName.c_str());

	}
	void getPressureMap3()
	{
		fprintf(mFile,"\"%s.spm3\"",mName.c_str());

	}
	void getPressureMin3()
	{
		fprintf(mFile,"\"%s.ps3\"",mName.c_str());

	}
	void getPressureMax3()
	{
		fprintf(mFile,"\"%s.px3\"",mName.c_str());

	}
	void getPressureScale(size_t psc_i)
	{
		fprintf(mFile,"\"%s.psc[%i]\"",mName.c_str(),psc_i);

	}
	void getPressureScale_Position(size_t psc_i)
	{
		fprintf(mFile,"\"%s.psc[%i].pscp\"",mName.c_str(),psc_i);

	}
	void getPressureScale_FloatValue(size_t psc_i)
	{
		fprintf(mFile,"\"%s.psc[%i].pscfv\"",mName.c_str(),psc_i);

	}
	void getPressureScale_Interp(size_t psc_i)
	{
		fprintf(mFile,"\"%s.psc[%i].psci\"",mName.c_str(),psc_i);

	}
	void getPressure(size_t psr_i)
	{
		fprintf(mFile,"\"%s.psr[%i]\"",mName.c_str(),psr_i);

	}
	void getUvSetName(size_t uvsetn_i)
	{
		fprintf(mFile,"\"%s.uvsetn[%i]\"",mName.c_str(),uvsetn_i);

	}
protected:
	Stroke(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PfxGeometry(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_STROKE_H__